#include "stm32f10x.h"
#include "stm32f10x_can.h"

// Định nghĩa ID
#define RPM_CAN_ID            0x100
#define TEMPERATURE_CAN_ID    0x101
#define OIL_PRESSURE_CAN_ID   0x102
#define AIR_INTAKE_CAN_ID     0x103
#define EXHAUST_POS_CAN_ID    0x104
#define VEHICLE_SPEED_CAN_ID  0x105
#define FUEL_CONSUMPTION_ID   0x106
#define ERROR_CAN_ID          0x7FF
#define SENSOR_ERROR_CODE     0x01

// Cấu trúc dữ liệu
CanRxMsg RxMessage;

// Khởi tạo CAN
void CAN_Config(void) {
    CAN_InitTypeDef CAN_InitStructure;

    // ... Các thiết lập khởi tạo GPIO cho CAN ...

    CAN_InitStructure.CAN_TTCM = DISABLE;
    CAN_InitStructure.CAN_ABOM = DISABLE;
    CAN_InitStructure.CAN_AWUM = DISABLE;
    CAN_InitStructure.CAN_NART = DISABLE;
    CAN_InitStructure.CAN_RFLM = DISABLE;
    CAN_InitStructure.CAN_TXFP = DISABLE;
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    CAN_InitStructure.CAN_BS1 = CAN_BS1_8tq;
    CAN_InitStructure.CAN_BS2 = CAN_BS2_7tq;
    CAN_InitStructure.CAN_Prescaler = 2;   // Tốc độ 500kbps với 72MHz system clock
    CAN_Init(CAN1, &CAN_InitStructure);
}

// Ghi dữ liệu vào SD card
void LogDataToSD(char *data) {
    // ... 
}

// Xử lý thông điệp từ CAN
void Process_CAN_Message() {
    CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);
    
    char logBuffer[100];
    
    switch (RxMessage.StdId) {
        case RPM_CAN_ID:
            uint16_t rpm = (RxMessage.Data[0] << 8) | RxMessage.Data[1];
            sprintf(logBuffer, "RPM: %d\n", rpm);
            LogDataToSD(logBuffer);
            break;
        
        case TEMPERATURE_CAN_ID:
            uint8_t temperature = RxMessage.Data[0];
            sprintf(logBuffer, "Temperature: %d C\n", temperature);
            LogDataToSD(logBuffer);
            break;

        // ... Xử lý và ghi cho các tham số khác ...

        case ERROR_CAN_ID:
            if (RxMessage.Data[0] == SENSOR_ERROR_CODE) {
                sprintf(logBuffer, "ERROR Detected: Sensor Error\n");
                LogDataToSD(logBuffer);
            }
            break;
    }
}

int main(void) {
    // Khởi tạo
    CAN_Config();
    // Khởi tạo SD nếu cần

    while (1) {
        // Kiểm tra có thông điệp mới từ CAN
        if (CAN_GetFlagStatus(CAN1, CAN_FLAG_FMP0)) {
            Process_CAN_Message();
        }
        // Thực hiện các chức năng khác hoặc đặt MCU vào chế độ tiết kiệm năng lượng
        /30s
    }

    return 0;
}