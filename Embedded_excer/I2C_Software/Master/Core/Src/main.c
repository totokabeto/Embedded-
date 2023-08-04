/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define I2C_PIN_SCL GPIO_PIN_10
#define I2C_PIN_SDA GPIO_PIN_11
#define I2C_GPIO_PORT GPIOB
#define I2C_READ 1
#define I2C_WRITE 0

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write(uint8_t);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void i2c_init(void)
{
  // Khởi tạo các chân GPIO cho I2C
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = I2C_PIN_SCL | I2C_PIN_SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStruct);

  // Đặt giá tr�? ban đầu cho các chân GPIO
  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL | I2C_PIN_SDA, GPIO_PIN_SET);
}

void i2c_start(void)
{
  // Đặt chân SDA th�?nh đầu ra v�? đặt giá tr�? HIGH
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = I2C_PIN_SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStruct);

  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SDA, GPIO_PIN_SET);
  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_SET);

  // Đợi một chút trước khi ghi giá tr�? LOW v�?o chân SDA
  HAL_Delay(1);

  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SDA, GPIO_PIN_RESET);

  // Đợi một chút trước khi ghi giá tr�? LOW v�?o chân SCL
  HAL_Delay(1);

  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_RESET);
}

void i2c_stop(void)
{
  // Đặt chân SDA th�?nh đầu ra v�? đặt giá tr�? LOW
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = I2C_PIN_SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStruct);

  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SDA, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_SET);

  // Đợi một chút trước khi đặt giá tr�? HIGH v�?o chân SDA
  HAL_Delay(1);

  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SDA, GPIO_PIN_SET);
}

void i2c_write(uint8_t data)
{
  // Ghi từng bit của dữ liệu v�?o chân SDA
  for (uint8_t i = 0; i < 8; i++) {
    if ((data & (1 << (7 - i))) != 0) {
      HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SDA, GPIO_PIN_SET);
    } else {
      HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SDA, GPIO_PIN_RESET);
    }

    // Đợi một chút trước khi ghi giá tr�? HIGH v�?o chân SCL
    HAL_Delay(1);

    HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_SET);

    // Đợi một chút trước khi ghi giá tr�? LOW v�?o chân SCL
    HAL_Delay(1);

    HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_RESET);
  }

  // Đợi một chút trước khi đọc giá tr�? ACK từ chân SDA
  HAL_Delay(1);

  // Đặt chân SDA th�?nh đầu v�?o v�? đọc giá tr�? ACK
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = I2C_PIN_SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStruct);

  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_SET);

  // Đợi một chút trước khi đọc giá tr�? ACK từ chân SDA
  HAL_Delay(1);

  uint8_t ack = HAL_GPIO_ReadPin(I2C_GPIO_PORT, I2C_PIN_SDA);

  HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_RESET);

  // Trả v�? giá tr�? ACK
  return ack == GPIO_PIN_RESET;
}

uint8_t i2c_read(uint8_t ack)
{
  uint8_t data = 0;

  // Đặt chân SDA th�?nh đầu v�?o v�? đọc từng bit của dữ liệu
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = I2C_PIN_SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStruct);

  for (uint8_t i = 0; i < 8; i++) {
    HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_SET);

    // Đợi một chút trước khi đọc giá tr�? từ chân SDA
    HAL_Delay(1);

    data |= (HAL_GPIO_ReadPin(I2C_GPIO_PORT, I2C_PIN_SDA) << (7 - i));

    HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_RESET);

    // Đợi một chút trước khi đọc giá tr�? từ chân SDA
    HAL_Delay(1);
  }

  // Ghi ACK hoặc NACK v�?o chân SDA
  GPIO_InitStruct.Pin = I2C_PIN_SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStruct);

    if (ack) {
      HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SDA, GPIO_PIN_RESET);
    } else {
      HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SDA, GPIO_PIN_SET);
    }

    // Đợi một chút trước khi ghi giá tr�? ACK hoặc NACK v�?o chân SCL
    HAL_Delay(1);

    HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_SET);

    // Đợi một chút trước khi ghi giá tr�? ACK hoặc NACK v�?o chân SCL
    HAL_Delay(1);

    HAL_GPIO_WritePin(I2C_GPIO_PORT, I2C_PIN_SCL, GPIO_PIN_RESET);

    // Trả v�? dữ liệu đọc được
    return data;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

	HAL_Init();


  /* USER CODE BEGIN Init */
	SystemClock_Config();
  /* USER CODE END Init */

  /* Configure the system clock */
  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */

  /* USER CODE BEGIN 2 */
	MX_GPIO_Init();
	i2c_init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	 /* for (uint8_t i = 1; i <= 100; i++) {
	        i2c_start();
	        i2c_write(0x27);
	        i2c_write(i);
	        i2c_stop();

	        // Đợi một chút trước khi gửi số tiếp theo
	        HAL_Delay(10);
	      }*/
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA5 PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
