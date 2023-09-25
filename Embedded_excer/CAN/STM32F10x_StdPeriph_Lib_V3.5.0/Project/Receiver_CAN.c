#include "stm32f10x.h"
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"


void init_CAN(uint16_t can_id){
 // dinh nghia ten 
    GPIO_InitTypeDef            GPIO_InitStructure; 
    CAN_InitTypeDef             CAN_InitStructure; 
    CAN_FilterInitTypeDef       CAN_FilterInitStructure; 
    // doc datasheet de biet CAN1 thuoc APB1 hay APB2)
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

    // chan 11 va chan 12 cua stm32 la chan can tx va can rx

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    // KHAI BAO RX 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;

    GPIO_Init(GPIOA, &GPIO_InitStructure);


     // khai bao CAN 
     /* CAN cell init */
    CAN_InitStructure.CAN_TTCM = DISABLE; // co the enalble duoc, disable thi khong set up thoi gian de gui , enable thi co, stm32 khong ho tro cai nay, co the code chay dc 
    CAN_InitStructure.CAN_ABOM = DISABLE; // ABO - automatic bus off - khi quá trình CAN truyền và bị lỗi thì lúc đó có chấp nhận bỏ qua cái lỗi đó hay quay lại gửi chương trình đó, gửi lại từ đầu - ENABLE , DISABLE nó sẽ tiếp túc gửi cái tiếp theo, tiếp nữa 
    CAN_InitStructure.CAN_AWUM = DISABLE; // AWUM - Automatic wakeup mode - chế độ ngủ của vi điều khiển, khi ko truyền nhận thì nó sẽ vào chế độ ngủ, tiết kiệm điện, khi nào nhận hoặc gửi thì nó mới thức dậy và gửi data 
    CAN_InitStructure.CAN_NART = DISABLE; // NART - có tự động gửi lại message, khi truyền data trường hợp truyền thiếu data hoặc bị sai ? ko nhận dc bit ACK, thì có gửi lại cái đoạn data đó ko ? disable nếu ko có ACK thì thôi, enalable ko ACK vẫn gửi lại message 
    CAN_InitStructure.CAN_RFLM = DISABLE; // RFLM - cho phép truyền theo kiểu FIFO, nếu cho phép thì phải set up sau, FIFO thì sẽ có 1 bộ nhớ đệm, đầy rồi sẽ nó sẽ xóa bit số 8 hay không hay giữ nguyên ? 
    CAN_InitStructure.CAN_TXFP = DISABLE; // TXFP - ưu tiên truyền dựa trên ID, ID càng thấp thì mức độ ưu tiên càng cao, disable thì nó sẽ ưu tiên thấp hơn, enable thì lúc đó phụ thuộc vào FIFO 
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal; // Mode 
    // Normal - che do thong thuong nhan gui thong thuong 
    // LoopBack - gui di 1 cai thi se co 1 bo nho dem doc lai cai do, dùng để debug cái gì gửi đi thì sẽ đọc lại được 
    // Silent - chế độ chỉ nhận data từ các node khác gửi về 
    // Silent_LoopBack - thường dùng để debug, gửi gói data đi và có 1 cái bộ nhớ đệm 
  /* CAN Baudrate = 1MBps*/
    // phan nay lien quan den toc do truyen cua CAN 
    // 3 thang cong lai nhan cho prescaler sau do chia cho tan so dao dong vd 50 MHz -> THOI GIAN 1 BIT NOT TRUYEN DI 
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    CAN_InitStructure.CAN_BS1 = CAN_BS1_3tq;
    CAN_InitStructure.CAN_BS2 = CAN_BS2_5tq;
    CAN_InitStructure.CAN_Prescaler = 4;
    CAN_Init(CAN1, &CAN_InitStructure);

     // cau hinh CAN 
    // cấu hình bọ lọc 0
    CAN_FilterInitStructure.CAN_FilterNumber = 0; 
    // 1 bộ lọc chỉ truyền cho 1 ID 
    CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
    CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
    CAN_FilterInitStructure.CAN_FilterIdHigh = can_id << 5; // tại sao 5 ? 0x123 phải dời qua để nó tự fill vào các bit đệm và các bit IDE, 0x123 dịch sang trái 5 bit // High là 16 bit sang trái 5 bit thì phía sau sẽ có chỗ cho bit đệm 0b0000 0001 0010 0011 -> chừa lại 5 bit trống ở cuối bao gồm 1 RTR , 1 IDE , 3 bit r0 (tự động fix = 0 theo frame chuẩn)
    // note dạng mở rộng phải tự set up bit r0 
    // MCU truyền cho 2 địa chỉ khác nhau, 2 nội dung khác nhau 2 id khác nhau thì sẽ dùng 2 bộ lọc khác nhau 
    CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0xFFFFF;
    CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0; // thuong se viet nhu the nay 
    CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
    CAN_FilterInit(&CAN_FilterInitStructure);
}
   
   //TEST 

   uint8_t TestArray[8]; 
void receive_Can_message(){
     CanRxMsg RxMessage;

    while (CAN_MessagePending(CAN1,CAN_FIFO0) < 1)
    {
        /* code */
    }
    CAN_Receive(CAN1,CAN_FIFO0, &RxMessage);
    for (int i = 0; i < RxMessage.DLC; i++){
        TestArray[i] = RxMessage.Data[i];
    }
    // phần này test 2 bộ lọc 

    /* 
    if(RxMessage.Stdid == 0x123){
        //
    } else if (RxMessage.STdid == 0x456){

    }
    */
}
uint8_t temperature[2] = {28,78};
void respondToDataRequest(){
    CanRxMsg rxMessage; 
    CanTxMsg TxMessage; 

    CAN_Receive(CAN1, CAN_FIFO0, &rxMessage); 
    
    if(rxMessage.StdId == (uint32_t)(0x123) && rxMessage.IDE == CAN_ID_STD && rxMessage.RTR = CAN_RTR_REMOTE){
        TxMessage.StdId = 0x321;  // truyền ngược lại địa chỉ 

         CanTxMsg    TxMessage; 

        TxMessage.StdId = 0x321; 
        TxMessage.ExtId = 0x00; 
        TxMessage.RTR = CAN_RTR_DATA; // chuẩn data frame
        TxMessage.IDE = CAN_ID_STD; // IDE chuẩn 
        TxMessage.DLC = 2; 
        for (int i = 0; i < 2;i++){
            TxMessage.Data[i] = temperature[i];
        }
        CAN_Transmit(CAN1,&TxMessage);
    }
}
void CAN_Sleep_Mode(){
    CAN_Sleep(CAN1);
        while(CAN_GetFlagStatus(CAN1,CAN_FLAG_SLAK == RESET)){
            // chờ đến khi vi điều khiển hoạt động , cờ bằng 1 
        }
}

void processSpeedData(uint16_t speedData){
    if(speedData >= 100){
        // bật led
    } else {
        // tắt led 
    }
}


void receiveSpeedData(){
    CanRxMsg RxMessage; 

    int retryCount = 0;
    // kiểm tra lại 3 lần 
    while (retryCount < 3)
    {
         // kiểm tra xem dữ liệu có nhận được hay không 
    if(CAN_MessagePending(CAN1, CAN_FIFO0) != 0){
        CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);

        if(RxMessage.StdId == 0x123 && RxMessage.IDE == CAN_ID_STD && RxMessage.DLC == 2){
            uint16_t speedData =(uint16_t) (RxMessage.Data[1] << 8) | RxMessage.Data[0];
            processSpeedData(speedData);
            break;
        }   
    } else { 
        // log lỗi ra hoặc yêu cầu nhận lại 
        retryCount++;
        delay(100); 
    }
    }
}
// error frame 
/*
Error frame - trong quá trình truyền bị nhiễu gây cho data bị lỗi dẫn đến toàn bộ data sẽ bị lỗi, check sum cũng sẽ bị sai 
2 cách xử lý : 
+In ra lỗi log - tương tự như C/C++ dùng prinf hay cout 
*/
// Overload Frame vi điều khiển không đáp ứng được tốc độ, thằng nhanh thằng chậm, truyền không kịp hoặc đợi không kịp , dây dài quá , cũng sẽ log lỗi giống như error frame 
int main(int argc, char const *argv[])
{
    while(1){
        init_CAN(0x123); 
        receive_Can_message();
    }
    return 0;
}

// phân biệt data frame và remote frame / remote frame node muốn đọc nhiệt độ độ ẩm node B kết nối , node a gửi tín hiệu yêu cầu node b gửi dữ liệu cho node a 



