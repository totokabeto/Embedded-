/**
  ******************************************************************************
  * @file    CAN/Networking/stm32f10x_it.h 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CAN_H
#define CAN_H
#include "stm32f10x.h"
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include <stdint.h>

typedef struct{
    uint8_t SJW;
    uint8_t BS1;
    uint8_t BS2;
    uint8_t Prescaler; 
    uint32_t FilterMaskID; // gộp chung cả idHigh và idLow
    uint32_t FilterId; 
    uint8_t TxBufferId; 
    uint8_t RxBufferId;


}Can_ConfigType;

typedef uint8_t Std_ReturnType;

#define E_OK  ((Std_ReturnType) 0x00) 
#define E_NOT_OK ((Std_ReturnType)0x01)

typedef uint16_t Can_HwHandleType;
typedef uint16_t PduIdType; 
typedef uint32_t Can_IdType;


typedef struct{
    PduIdType swPduHandle; // có thể là định nghĩa uint8 hoặc 16
    uint8_t length; 
    Can_IdType id; 
    uint8_t* sdu;
}Can_PduType; 


void Can_Init(const Can_ConfigType* Config);
Std_ReturnType Can_Write (Can_HwHandleType Hth,const Can_PduType* PduInfo);
#endif 