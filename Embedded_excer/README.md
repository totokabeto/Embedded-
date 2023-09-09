# Phần về nhúng 

## SPI 

### SPI là gì ? 

SPI (Serial Peripheral Interface) là một chuẩn truyền thông nối tiếp tốc độ cao do Motorola đề xuất.

Bus SPI bao gồm các chân : 

- SCLK : chân xung clock 
- MOSI : master cho slaver
- MISO : slaver cho master
- CS hoặc SS 

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/97/SPI_three_slaves_daisy_chained.svg/1200px-SPI_three_slaves_daisy_chained.svg.png">

Do 2 chân gửi và nhận là 2 chân tách biệt nên tại 1 thời điểm master có thể vừa truyền vừa nhận. 

- chân của master sẽ nối với slave tương ứng 
- một master sẽ đấu nối được nhiều slaver theo kiểu song song
- slaver có 1 ss còn master thì kết nối bao nhiêu thì sẽ có bấy nhiêu chân ss 
- tại 1 thời điểm thì 1 master giao tiếp với 1 slave. 

### Cách truyền data của giao thức SPI : 

giả sử ta muốn gửi 1 mảng ký tự 
char arr[] = "Hello" từ 1 MCU sang MCU = SPI

tách ra theo mã ASCII -> Binary 
0b01001000 -> 0.....
```C
if (SCL == 1){
	read MISO; // đọc chân MISO 
}
```
mỗi bit sẽ được truyền thông qua chân SCL thay đổi trạng thái. 


<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/6/6b/SPI_timing_diagram2.svg/400px-SPI_timing_diagram2.svg.png">

c pol hình dạng xung clock 
c pol = 0 lúc đầu ko truyền sẽ = 0;  🡪 chân SCK 
c pol = 1 lúc đầu ko truyền sẽ mức 1;

c pha = 0 đưa data vào chan miso cần xung scl để đẩy data đi 
c pha = 1 xung scl trước sau đó đưa data vào.


các mode hoạt động của giao thức SPI : 

<img src="https://hackaday.com/wp-content/uploads/2018/06/spi-mode-table.png">


## I2C 

I2C chỉ sử dụng hai dây để truyền dữ liệu giữa các thiết bị:
 
SDA (Serial Data) - đường truyền cho master và slave để gửi và nhận dữ liệu.
 
SCL (Serial Clock) - đường mang tín hiệu xung nhịp.
 
I2C là một giao thức truyền thông nối tiếp, vì vậy dữ liệu được truyền từng bit dọc theo một đường duy nhất (đường SDA).
 
I2C là đồng bộ, do đó đầu ra của các bit được đồng bộ hóa với việc lấy mẫu các bit bởi một tín hiệu xung nhịp được chia sẻ giữa master và slave. Tín hiệu xung nhịp luôn được điều khiển bởi master.

<img src="https://www.totalphase.com/media/blog/2021/02/10260243_diagram-original.jpg">

SDA :chân truyền data

SCL : chân xung clock

khi không giao tiếp thì 2 chân này đều mức cao vì được đấu nối pull-up. 

### Làm sao master có thể truyền cho slaver được ? 

<img src="https://www.totalphase.com/media/support/article_attachments/200052148/slave-address-fig2.png">

Giả sử các slave có địa chỉ là 0x01     0x02        0x03

master gửi 1 bit tín hiệu ? 

MCU B : 
```C
uint8_t addr = 0x01; 
uint8_t data; 

if(SCL == 1) {
data = read SDA 
}
```
MCUB sẽ kiểm tra byte đầu tiên check xem nó có giống với địa chỉ cố định của slave hay ko
nếu đúng thì cho phép truyền dữ liệu tiếp. 

Vì chỉ có 1 chân SDA nên tất cả slave đều nhận được tín hiệu, chi có thể phân biệt bằng địa chi.

### I2C Data frame 

<img src="https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-I2C-Message-Frame-and-Bit-2.png">

khi ko giao tiếp, 2 chân = 1; 
```C++
if (SDA == 0){
	while(SCL == 0) {
	}
}
```
+ start bit : kéo 2 chân về 0; 

+ sau khi truyền hết 7 bit địa chỉ và 1 bit thông báo đọc hoặc ghi  thì chân SCL đôi trạng thái và gửi 1 bit ACK 
master từ IN sẽ đổi sang OUT và slave từ OUT sang IN 

+ do chân SCL luôn ở mức 1 nên khi đổi trạng thái thì 
từ slave sẽ gửi bit 0 về cho master

+ nếu slave nhận được data thì nó sẽ tự truyền về cho master bit 0 

bit 0 đó gọi là bit ACK

+ bit ACK, thông báo master rằng slave nhận dc 1 byte 

+ nếu hết thời gian timeout mà slave ko gửi thì tức là master ko gửi dc data

+ timeout 0 - 100; 

+ nếu timeout hết tức ko gửi được thì quá trình diễn ra lại từ đầu. 
(do hardware quy định)
 
+ timeout do mình set tùy vào mong muốn đáp ứng phản hồi nhanh hay chậm 

+sau khi nhận được ACK tiếp tục đổi trạng thái chan SCL từ IN - OUT thì OUT - IN và truyền data 

+ stop bit : kéo SCL lên mức 1 sau đó SDA cũng sẽ kéo từ 0 lên 1. 

## UART 


<img src="https://vanhunteradams.com/Protocols/UART/uart_hardware.png">


Tx : chân Transmit - truyền data 

Rx : chân Receiver - nhận data 

vì 2 chân độc lập nên tại 1 thời điểm có thể vừa gửi vừa nhận dữ liệu 

### không có xung clock làm sao có thể biết được lúc nào nhận và lúc nào gửi dữ liệu 

thực ra chân Tx và Rx đều có điện trở kéo lên và ở mức 1 

<img src="https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-UART-Packet-Frame-and-Bits-2.png">

1 start bit : kéo điện áp Tx từ mức 1 xuống mức 0; 

Tx = 1 -> Tx = 0 : start bit 
```c++
if (RX == 0){
	timer() (MCUB)
}
```

khởi tạo timer() 0-10 (MCUA)

timer() đều đếm giống nhau 

TX = 1 timer() nhảy vào ngắt và truyển bit 1 đi (ví dụ) ; đẩy đi và bên kia đọc 

do timer() có thời gian bằng nhau nên giúp 2 con vxl nó đồng bộ với nhau 

0-10 được gọi là baudrate 

### Baudrate là gì ? 

1s thực hiện 9600 dao động 

đẩy đi 9600 bits 

1s = 1000ms = 9600 

1000/9600 = 1 dao động = 0,104(ms) 

tức 0,104 ms mới thực hiện được 1 dao động 1(T)

set-up 1 timer từ (0-0,104) 

8 bits data + 1 bit chẵn lẻ 

 bit chẵn lẻ 0 hoặc 1 

quy luật số chẵn 

đếm số 1 nếu số 1 là lẻ thì bit chẳn lẽ sẽ thêm 1 bit số 1 cho chẵn 

quy luật số lẻ 

<img src="https://i.stack.imgur.com/p6eh7.png">
Tại sao ? 

xung clock ổn định hơn nhưng timer thì có thể bị lệch 

nên phải thêm bit chẵn lẻ đế check xem data có truyền đúng hay ko 

mcub sẽ kiếm tra theo quy luật được ghi trên datasheet 

sau đó là 1 bit stop, Tx kéo từ mức 0 lên mức 1 

2 bit stop thì nó kéo 2 lần trong khoảng thời gian ngắn

## Ngắt - Interrupt 

### Ngắt là gì ? 

Chương trình có các độ ưu tiên khác nhau 
ngắt là 1 chương trình chạy độc lập với chương trình chính và có độ ưu tiên cao hơn 

các ngắt trong vxl 

ISR (trình phục vụ ngắt) 

Mỗi vxl sẽ có Bảng vector ngắt
muốn sử dụng loại ngắt nào thì đăng ký loại ngắt đó vào bảng vector ngắt 

<img src="https://microcontrollerslab.com/wp-content/uploads/2020/09/What-is-interrupt-vector-table.jpg">

Vd : Ngắt reset có độ ưu tiên cao nhất nhấn reset thì program counter sẽ trỏ tới vị trí 0x00 

Mỗi loại ngắt sẽ có địa chỉ và thứ tự ưu tiên ngắt khác nhau 

Số thứ tự ưu tiên càng thấp thì độ ưu tiên của nó càng cao 

Khi xảy ra ngắt nào thì con trỏ program counter sẽ trỏ tới địa chỉ ngắt đó và chạy chương trình đó 

### Ngắt ngoài là gì ? 

Gỉa sử 1 con vxl có 1 cái port nối với 1 công tắc 
vì công tắc luôn được kéo lên thì khi nhấn nút 0 thì nó sẽ xảy ra ngắt 


<img src="https://i0.wp.com/dronebotworkshop.com/wp-content/uploads/2022/05/arduino-uno-pin-change-port-b.jpg?resize=750%2C422&ssl=1">


ngăt ngoài tiếng anh là attachInterrupt 
ví dụ arduino : 
LOW,HIGH,FALLING,RISING 

xung cạnh lên và xung cạnh xuống. Gỉa sử chân mức 0 và có 1 nút nhấn có tốc độ rất nhanh thì lúc transition từ 0 sang 1 thì nó xảy ra ngắt ngay lập tức 
-> tốc độ đáp ứng phải
 cao và không bị nhiễu 
ngược lại, tức luôn ở mức 1 và nút nhấn về 0 


Ngắt truyền thông 
SPI, UART , I2C đều dc gọi là ngắt truyền thông 

MCUA ------------ MCUB 

while(1){	while(1){
A();		Receive();
Transmit();	A();
B(); 		B();

}		}

2 bên ko đồng bộ 2 thời điểm truyền và nhận nó khác nhau nên không thể đọc được 
Chương trình nhỏ thì may ra có thể đọc được 

TX - RX; 

giả sử dùng ngắt uart 
khi chân RX có data thì dừng chương trình chính và nhảy vào chương trình ngắt 
### Ngắt hoạt động như thế nào ? 

Gỉa sử : Ngắt ngoài > ngắt timer 


0x01 




0x07 

0xc1 Ngắt ngoài 




0xc5 


0xa3 Ngắt timer  



0xa9 


0x01 0x02 0x03 
main -> 0x03 ngắt timer -> 0xa4 ngắt ngoài 

### Luồng chương trình chạy ntn ? 

0x01 - 0x03 -> lưu 0x04 vào stack pointer -> chạy ngắt timer -> 0xa3 - 0xa4 nó thấy ngắt ngoài có độ ưu tiên cao hơn ngắt timer - lưu 0xa5 vào stack pointer -> 0xc1 - 0xc5 -> vào stack pointer lấy 0xa5 ra và chạy 0xa5 - 0xa9 -> vào stack pointer lấy 0x04 - 0x09

Gỉa sử ngắt timer > ngắt ngoài thì sao ? 

0x01 - 0x03 -> 0xa3 - 0xa9 (kiểm tra xem ngắt ngoài còn tín hiệu hay không ) -> 0xc1 - 0xc5 -> 0x04 - 0x09;

Câu hỏi : biến volatile liên quan gì đến interrupt ?


## Timer 

Lấy ví dụ thư viện của STM8 bộ thư 
viện tiêu chuẩn 

Cách cấu hình 1 timer, tất cả 
vdk đều qua các bước này 

1.TIM4_TimerBaseInit(Prescaler,Period)

giả sử vdk 16 MHz; 

16 MHz = 16000000 Hz 

ứng dụng timer, băm xung điều khiển 
động cơ, tạo delay ms nanos 

prescaler dùng để chia nhỏ tốc độ ra 
vì các ứng dụng ko cần thiết phải có 
tốc độ lớn như vậy 
prescaler 128
16.000.000 / 128 = 125.000 Hz

1s thực hiện được 125.000 dao động 

giả sử muốn viết 1 chương trình 
1ms ngắt 1 lần 

1s = 1000 ms = 125.000 Hz 
	1 ms = 125 Hz 
1ms dao động được 125 lần 

1 dao động thì bộ đếm timer đếm lên 1 lần 

125 thì bắt đầu từ 0 - 124 => period = 124 
có 125 ô nhớ đếm đến 124 sang 125 thì sẽ bị tràn 
khoảnh khác từ 124 đến 125 sẽ bị tràn 

124 gọi là giới hạn bộ đếm 

2.Clear_Tim4_update_flag 

khi đếm 125 sẽ xảy ra ngắt và có 1 cái cờ tràn 
khi tràn sẽ xảy ra ngắt và người ta sẽ xóa cái cờ tràn 

### tại sao ? 

khi khởi động vđk thì cờ ko tràn 
1 chương trình có nhiều người sử dụng timer 4 thì sao 
lúc đó timer 4 vẫn chạy và có thể báo cờ tràn 

3.Enable update interrupt -> đăng ký ngắt timer vào bảng vector ngắt 

4.enableInterrupt() : Cho phép tất cả ngắt được đăng ký hoạt động 

5.sau đó mới tới bước enable timer 4

##  CAN 

### CAN là gì ? 

CAN là một giao thức nối tiếp, tốc độ cao, sử dụng 2 dây đặc trưng bởi khả năng chống nhiễu tốt được sử dụng trong ngành ô tô 

Cách trả lời phỏng vấn CAN : 

1. Nói về cấu tạo 
2. Nói về cách chống nhiễu (xoắn dây)
3. Nói về tốc độ, node , CAN High, CAN Low 
4. Nói về data Frame / Standard Frame và Extension Frame

2 dây high và low bị bắt xoắn với nhau, dòng điện đi qua thì tạo ra dòng điện cảm ứng 
tạo ra từ trường gây nhiễu, 2 dây sẽ bị nhiễu đồng thời 
nếu mắc song song thì dây nào ở gần hơn thì nhiễu nhiều hơn, xa hơn thì nhiễu ít hơn 

bắt xoắn thì nhiễu bằng nhau, trị tuyệt đối vẫn duy trì như cũ 

CAN Transceiver là 1 bộ riêng dùng để xuất điện áp ra chân can high - can low

làm sao biết node nào truyền và node nào nhận ? 

ID ? 

MCU A : 00010 

MCU B : 00100

MCU C : 00011

đồng cấp ko con nào là master và con nào là slave 

tại 1 thời điểm có 1 con truyền và tất cả các con còn lại sẽ nhận  

bit 1: 
CAN HIGH = 4 , LOW = 1
bit 0: 
CAN HIGH = 1,75, low 3,25 

truyền ra và nhận ngược lại y chang 
xuất và đọc y chang thì nó hiểu là chỉ có mình nó đang truyền 

nếu khác thì truyền data đi và cùng 1 thời điểm cũng sẽ có thằng khác đang truyền 

giao thức CAN thì địa chỉ càng nhỏ thì ưu tiên càng cao, ưu tiên bit 0 

sau đó sẽ dừng quá trình truyền và nhảy vào quá trình nhận data 

ưu tiên truyền 

phan biet 2 bit 0 lien tiep 

timer() 

khi chạy timer thì can high và can low hiệu cũng sẽ bằng 0, 2 chân thả nổi 

sau khi hết timer thì gửi 1 bit dominant thì đó là bit 0 tiếp theo 

Thông số CAN low speed                      CAN high speed

Tốc độ 125 kb/s                              125 kb/s tới 1Mb/s
số nút trên bus 2 tới 20                         2 tới 30
Trạng thái dominant CAN H = 4V ; CAN L = 1V              CAN H = 3,25V ; CAN L = 1,5V
Trạng thái recessive CAN H = 1,75V ; CAN L = 3,25V       CAN H = 2,5V ; CAN L = 2,5V
tính chất cӫa cap 30pF giữa cáp và dây              2*120 ohm
Mӭc điện áp cung cấp 5V 5V

Dataframe : 


<img src="https://elearning.vector.com/pluginfile.php/515/mod_page/content/14/CAN_3.2_GRA_StandardExtendedDataFrame_EN.png">

Data Frame CAN (Phiên bản 2.0A) tiêu chuẩn bao gồm bảy trường bit khác nhau:

    1. Trường bắt đầu khung (Start Of Frame Field – SOF)

Với cả 2 định dạng của chuẩn CAN 2.0 thì trường bắt đầu là vị trí của bit đầu tiên
trong khung. Trường này chiếm 1 bit dữ liệu. Bit đầu tiên này là một Dominant Bit
(mức logic 0) đánh dấu sự bắt đầu của một Data Frame.

    2. Trường xác định quyền ưu tiên (Arbitration Field)

Định dạng vùng xác định quyền ưu tiên là khác nhau đối với dạng khung chuẩn và
khung mở rộng.

● Định dạng chuẩn: vùng xác định quyền ưu tiên có độ dài 12 bit, bao gồm
11 bit ID và 1 bit RTR.

● Định dạng mở rộng: trường xác định quyền ưu tiên có độ dài 32 bit, bao
gồm có 29 bit ID, 1 bit SRR, 1 bit IDE và 1 bit RTR

Trong đó:

Bit RTR (Remote Transmission Request)

● Là bit dùng để phân biệt khung là Data Frame hay Remote Frame.

● Nếu là Data Frame, bit này luôn bằng 0 (Dominant Bit).

● Nếu là Remote Frame, bit này luôn bằng 1 (Recessive Bit).

● Vị trí bit này luôn nằm sau bit ID.

Trường hợp nếu Data Frame và Remote Frame có cùng ID được gửi đi đồng thời thì
Data Frame sẽ được ưu tiên hơn.

Bit SRR (Substitute Remote Request)

● Bit này chỉ có ở khung mở rộng.

● Bit này có giá trị là 1 (Recessive Bit).

● So với vị trí tương ứng trong khung chuẩn thì bit này trùng với vị trí của bit

RTR nên còn được gọi là bit thay thế (Substitute).

Giả sử có hai Node cùng truyền, một Node truyền Data Frame chuẩn, một Node
truyền Data Frame mở rộng có ID giống nhau thì Node truyền khung chuẩn sẽ thắng
phân xử quyền ưu tiên vì đến vị trí sau ID, khung chuẩn là bit RTR = 0, còn khung
mở rộng là bit SRR = 1. Như vậy, khung chuẩn chiếm ưu thế hơn so với khung mở
rộng khi có ID như nhau.

Bit IDE (Identifier Extension)
● Đây là bit phân biệt giữa loại khung chuẩn và khung mở rộng: IDE = 0 quy
định khung chuẩn, IDE = 1 quy định khung mở rộng.

● Bit này nằm ở trường xác định quyền ưu tiên với khung mở rộng và ở
trường điều khiển với khung chuẩn.

3. Trường điều khiển (Control Field)

Khung chuẩn và khung mở rộng có định dạng khác nhau ở trường này:

● Khung chuẩn gồm IDE, r0 và DLC (Data Length Code).

● Khung mở rộng gồm r1, r0 và DLC.

Trong đó:

Bit IDE

Dùng phân biệt loại khung (đã được trình bày ở trên).

Bit r0, r1 (hai bit dự trữ)

Tuy hai bit này phải được truyền là Recessive Bit bởi bộ truyền nhưng bộ nhận
không quan tâm đến giá trị 2 bit này. Bộ nhận có thể nhận được các tổ hợp 00, 01,
10 hoặc 11 của r1 và r0 nhưng không coi đó là lỗi mà bỏ qua và nhận thông điệp
bình thường.

DLC (Data Length Code)

● Có độ dài 4 bit quy định số byte của trường dữ liệu của Data Frame

● Chỉ được mang giá trị từ 0 đến 8 tương ứng với trường dữ liệu có từ 0 đến
8 byte dữ liệu. Data Frame có thể không có byte dữ liệu nào khi DLC = 0.

● Giá trị lớn hơn 8 không được phép sử dụng. Hình dưới mô tả các loại mã
bit mà DLC có thể chứa để quy định số byte của trường dữ liệu.

4. Trường dữ liệu (Data Field)

Trường này có độ dài từ 0 đến 8 byte tùy vào giá trị của DLC ở trường điều khiển.

5. Trường kiểm tra (Cyclic Redundancy Check Field – CRC)

Trường kiểm tra hay trường CRC gồm 16 bit và được chia làm hai phần là:

● CRC Sequence: gồm 15 bit CRC tuần tự

● CRC Delimiter: là một Recessive Bit làm nhiệm vụ phân cách trường CRC
với trường ACK

● Mã kiểm tra CRC phù hợp nhất cho các khung mà chuỗi bit được kiểm tra
có chiều dài dưới 127 bit, mã này thích hợp cho việc phát hiện các trường
hợp sai nhóm (Bus Error). Ở đây, tổng bit từ trường bắt đầu (SOF) đến
trường dữ liệu (Data Field) tối đa là 83 bit (khung định dạng chuẩn) và 103
bit (khung định dạng mở rộng).

=> Trường CRC bảo vệ thông tin trong Data Frame và Remote Frame bằng cách
thêm các bit kiểm tra dự phòng ở đầu khung truyền. Ở đầu khung nhận, cũng sẽ tính
toán CRC như bộ truyền khi đã nhận dữ liệu và so sánh kết quả đó với CRC
Sequence mà nó đã nhận được, nếu khác nhau tức là đã có lỗi, nếu giống nhau tức
là đã nhận đúng từ trường SOF đến trường dữ liệu.

6. Trường báo nhận (Acknowledge Field – ACK)

Trường báo nhận hay trường ACK có độ dài 2 bit và bao gồm hai phần là ACK Slot
và ACK Delimiter.

● ACK Slot: có độ dài 1 bit, một Node truyền dữ liệu sẽ thiết lập bit này là
Recessive. Khi một hoặc nhiều Node nhận chính xác giá trị thông điệp
(không có lỗi và đã so sánh CRC Sequence trùng khớp) thì nó sẽ báo lại
cho bộ truyền bằng cách truyền ra một Dominant Bit ngay vị trí ACK Slot
để ghi đè lên Recessive Bit của bộ truyền.

● ACK Delimiter: có độ dài 1 bit, nó luôn là một Recessive Bit. Như vậy, ta
thấy rằng ACK Slot luôn được đặt giữa hai Recessive Bit là CRC Delimiter
và ACK Delimiter.

7. Trường kết thúc (End Of Frame Field – EOF)

Trường EOF là trường thông báo kết thúc một Data Frame hay Remote Frame.

Trường này gồm 7 Recessive Bit.

### Config CAN 
Những điều cần nhớ khi học chi tiết về CAN 

CAN Transmit : 

```C++
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
```
CAN_Receive : 

```C++
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
```
### Remote Frame 
    ```C
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
```
### Error Frame 
```C
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
```
### Viết CAN chuẩn AUTOSAR 

```C
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

```







