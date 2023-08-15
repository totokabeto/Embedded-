#include "stm32f10x.h"
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

void init_can(){
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
    CAN_InitStructure.CAN_TTCM = DISABLE;
    CAN_InitStructure.CAN_ABOM = DISABLE;
    CAN_InitStructure.CAN_AWUM = DISABLE;
    CAN_InitStructure.CAN_NART = DISABLE;
    CAN_InitStructure.CAN_RFLM = DISABLE;
    CAN_InitStructure.CAN_TXFP = DISABLE;
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
  
  /* CAN Baudrate = 1MBps*/
    // phan nay lien quan den toc do truyen cua CAN 
    // 3 thang cong lai nhan cho prescaler sau do chia cho tan so dao dong vd 50 MHz -> THOI GIAN 1 BIT NOT TRUYEN DI 
    // giả sử 8MB -> 8/4 = 2 -> 1/2 = 0,5 /  công thức : 1/(8/4) = 0,5 micro giay / 8 là tần số giao động của vi điều khiển 
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq; // SJW - thời gian đồng bộ giữa các node - giả sử các node ở rất xa nhau nên khi truyền data thì nó sẽ bị trễ , không đồng bộ được với nhau, các node ở gần thì sẽ truyền nhanh , còn các node ở xa thì lại truyền chậm 
    CAN_InitStructure.CAN_BS1 = CAN_BS1_3tq; // bit segment 1 - thời gian nó có thể đợi để nhận các data - khoảng thời gian trễ đâu ----- bit ---------- khoảng thời gian trễ sau / khoàng thời gian dầu mất thời gian để đến với node và do khoảng cách vật lý, thời gian trễ sau là thời gian node xử lý và gửi lại cho node gửi trước đó 
    CAN_InitStructure.CAN_BS2 = CAN_BS2_5tq;
    // 1 + 3 + 5 là thời gian tối đa mà nó truyền 
    
    CAN_InitStructure.CAN_Prescaler = 4;    // time quanta - thời gian để gửi đi 1 bit - prescaler nằm trong công thức để tính ra timer quata
    CAN_Init(CAN1, &CAN_InitStructure);
    // cau hinh CAN 
    // bộ lọc ID tùy thuộc vào vđk, STM32 hỗ trợ 14 bộ lọc từ 0 - 13, bộ lọc này là dùng để lọc các ID
    CAN_FilterInitStructure.CAN_FilterNumber = 0; // thường thì sẽ setup = 0, khi truyền nhiều thì có thể set up 1-4 
    CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask; // IDMask và IDList - cho phép lọc messages dựa trên bit mask, thao tác bit, bit && với ID, nếu khớp thì nó sẽ chấp nhận, id truyền và nhận bằng nhau. IDList nếu muốn nhận data truyền khác nhau, truyền theo 1 danh sách đã thiết lập sẵn, id list cho phép nhận nhiều id khác nhau, nhận data từ nhiều node khác nhau  
    CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit; // 2 loại 2 id 64 bit va 32 bit tùy cách mình set up 
    CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000; // 0x1234 2 byte  0x123xxxxxx
    CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000; // 0x5678 2 byte 
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000; //             0x111xxxxxx nó sẽ AND vs bên trên 
    CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000; // tức là thằng nào truyền nó cũng sẽ nhận được và không biệt ID nào cả 
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0; // thuong se viet nhu the nay // chon che do FIFO0 hay FIFO1
    CAN_FilterInitStructure.CAN_FilterActivation = ENABLE; // kích hoạt bộ lọc 
    CAN_FilterInit(&CAN_FilterInitStructure);
}   
    void send_Can_message(uint32_t id, uint8_t *data, uint8_t length){
        CanTxMsg    TxMessage; 

        TxMessage.StdId = id; 
        TxMessage.ExtId = 0x00; 
        TxMessage.RTR = CAN_RTR_DATA; // chuẩn data frame
        TxMessage.IDE = CAN_ID_STD; // IDE chuẩn 
        TxMessage.DLC = length; 
        for (int i = 0; i < 8;i++){
            TxMessage.Data[i] = data[i];
        }
        CAN_Transmit(CAN1,&TxMessage);
    }

// test remote frame : 

void requestTemperatureData(){
    CanTxMsg txMessage; 
    txMessage.StdId = 0x123; 
    txMessage.ExtId = 0x00; 
    txMessage.RTR = CAN_RTR_REMOTE; // chuẩn data frame
    txMessage.IDE = CAN_ID_STD; // IDE chuẩn 
    txMessage.DLC = 0; // GỬI Thông điệp chứ ko gửi data nên = 0; 

    CAN_Transmit(CAN1, &txMessage); // node nào nhận dc thông điệp thì sẽ phản hồi 
}


// error frame 
/*
Error frame - trong quá trình truyền bị nhiễu gây cho data bị lỗi dẫn đến toàn bộ data sẽ bị lỗi, check sum cũng sẽ bị sai 
2 cách xử lý : 
+In ra lỗi log - tương tự như C/C++ dùng prinf hay cout 
*/
void sendSpeedData(uint16_t speedData){
    CanTxMsg TxMessage; 

    // cấu hình thêm 

    TxMessage.StdId = 0x123; 
    TxMessage.IDE = CAN_ID_STD; 
    TxMessage.DLC = 2; 

    TxMessage.Data[0] = (uint8_t)(speedData & 0xFF);
    TxMessage.Data[1] = (uint8_t)((speedData >> 8) & 0xFF); // tạo ra tốc độ ngẫu nhiên 

    CAN_Transmit(CAN1, &TxMessage);

    if(CAN_Transmit(CAN1, &TxMessage) != CAN_TxStatus_Ok){
        // error 
        // ví dụ : logError 
        // logError("Error while trasmit speed data"); 

        //cách 2 gửi lại 
        for (int i = 0; i < 3; i++){
            if(CAN_Transmit(CAN1, &TxMessage) != CAN_TxStatus_Ok){
                break; 
            }

            delay(100); //nếu ko nó sẽ bị nghẽn  
        }
    } 
}
int main(int argc, char const *argv[])
{   
    init_can();
    uint8_t data[8] ={ 1,4,5,6,7,8,1,2};
    
    CanTxMsg txMessage; 

    // nếu FIFO dc enalble cho phép thì nó sẽ truyền message nào khai báo trước 
    txMessage.StdId = 0x003; 
    // 
    CAN_Transmit(CAN1,&txMessage);

  //test silent loopback 
    CanRxMsg rxMessage; 

    CAN_Receive(CAN1, CAN_FIFO0, &rxMessage);

    // DOC rxMessage , truyen di o chan TX do hardware thi RX cung nhan dc data, co the dung cai nay de debug 





    txMessage.StdId = 0x001; 
    //
    CAN_Transmit(CAN1,&txMessage);
    
    uint16_t speedData = 500; 
    
    while(1){
        send_Can_message(0x123, data, 8);
        
        //sendSoeedData(sppedData); 
        // delay
    }
    return 0;
}

