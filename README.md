# Embedded-
# Bài 1 Compiler 
Vi xử lý có thể hoạt động là do cấu tạo bao gồm nhiều con transistor với nhau 

có nhiều loại compiler : ví dụ `gcc`
`define MAX 10` là một loại macro 

Kiểu dữ liệu là gì ? 

Quá trình tiền xử lý được gọi là `preprocessor` quá trình này chẳng qua là biên dịch lại file `.c` và `.h` [hay còn gọi là source file] sang dạng file `main.i` hay còng được gọi là `preprocessed source`, quá trình nãy cũng là copy toàn bộ các file chứa trong `#include` 

một dạng macro khác ví dụ hàm macro 

`define Sum(a,b a+b `

Vậy quá trình tiền xử lý có thể gồm các việc sau : 
- Gán define, thay thế giá trị vào các chỗ gọi macro 
- xóa comment 
- copy file trong các thư mụ thư viện vào file `main.c `

*Các ngôn ngữ bậc cao hơn như Python thì phải bao gồm thêm một bước biên dịch sang ngôn ngữ C trước khi đến bước tiền xử lý, nên tốc độ xử lý có thể chậm hơn* . Do đó ngôn ngữ C rất gần với ngôn ngữ máy 

-Qúa trình tiếp theo là quá trình compiler chuyển từ file main.i sang file main.s hay còn gọi là file assembly code

-Tiếp đó là quá trình Assembler chuyển thành file main.o hay main.obj tại bước này các file thư việc của âm thanh và hình ảnh sẽ được thêm vào 

-Bước cuối cùng là Linker chuyển thành dạng file main.exe [đổi với Windows] để người dùng có thể run 

<img src="https://i.ytimg.com/vi/LOWQg8BNQJ4/maxresdefault.jpg">

# Bài 2 Memory Layout 

Các dữ liệu sẽ luôn được khởi tạo ở vùng nhớ RAM

Do tài nguyên không được nhiều nên chúng ta luôn cần phải tối ưu bộ nhớ 

## Các vùng nhớ 
Phân vùng nhớ
 <img src="https://courses.engr.illinois.edu/cs225/fa2022/assets/notes/stack_heap_memory/memory_layout.png">

•	Text :
– Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.

– Chứa khai báo hằng số trong chương trình (.rodata) vd : char * arr2 = “Hello” 

•	Data:

– Quyền truy cập là read-write.

– Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.

– Được giải phóng khi kết thúc chương trình.

•	Bss:

– Quyền truy cập là read-write.

– Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.

– Được giải phóng khi kết thúc chương trình.

•	Stack:
– Quyền truy cập là read-write.

– Được sử dụng cấp phát cho biến local, input parameter của hàm,…

– Sẽ được giải phóng khi ra khỏi block code/hàm

•	Heap:
– Quyền truy cập là read-write.

– Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …

– Sẽ được giải phóng khi gọi hàm free,…

ví dụ : uint8_t* ptr = (uint8_t*) malloc(sizeof(uint_8)*5);  Cấp phát động một mảng có giá trị là 5 byte. 

Khởi tạo con trỏ để lưu địa chỉ biến đầu tiên, ép kiểu và hàm malloc trả về một con trỏ void. Con trỏ giá 

trị nào thỉ chỉ lưu được giá trí đó mà thôi, muốn lưu giá trị khác ta phải tiến hành ép kiểu type cast 

Realloc() là hàm thay đổi kích thước của mảng mà mình đã cấp phát động

Vd : `arr = (uint8_t*)realloc(arr,sizeof(uint8_t)*3); `

Thay đổi mảng đã cấp phát động từ 5 byte về còn 3 byte 

Sự khác biệt giữa hàm calloc và malloc 

Khác biệt rõ rệt mà có thể thấy được là hàm calloc sẽ gán giá trị = 0 một cách tự động cho các phần tử trong 

mảng mà người dùng khởi tạo. Hơn nữa còn khác biệt về mặt tốc độ nếu ta tìm hiểu sâu 

*Note :*

Mảng là những địa chỉ liền kề nhau, bản thân mảng đã lưu địa chỉ của phần tử đầu tiên 

arr : địa chỉ 

*arr : giá trị 

# Bài 3 Macro&Function 

# Bài 4 Thao tác bit 

Tiếng Anh gọi là bitwise operator 

## And 

Các phép `&` thao tác được thực hiện cho các mã nhị phân và *tương tự như một phép nhân đại số*

muốn giữ lại bit đầu tiên ta thường dùng `AND`

0b1000000 & 0b10010001 = 10000000 

| A | B | A & B| 
|--------------|-------|------|
| 0 | 0| 0| 
| 0 | 1 | 0 | 
| 1 | 0 | 0| 
| 1 | 1 | 1| 

0x0 = 0; 1x1 = 1; 

`1. AND 
unsigned char a = 5; // 00000101

unsigned char b = 6; // 00000110
`
## NOT ~

| A | NOT A |  
|--------------|-------|
| 0 | 1| 
| 1 |0 |  

## OR |

Tương tự như một phép cộng đại số 

| A | B | A OR B| 
|--------------|-------|------|
| 0 | 0| 0| 
| 0 | 1 | 1 | 
| 1 | 0 | 1| 
| 1 | 1 | 1| 

0 + 0 = 0; 1 + 0 = 1; 1 + 1 = 2 nhớ 1 

## XOR ^ 

2 cái giống nhau thì XOR sẽ ra 0 

| A | B | A XOR B| 
|--------------|-------|------|
| 0 | 0| 0| 
| 0 | 1 | 1 | 
| 1 | 0 | 1| 
| 1 | 1 | 0| 

## Dịch trái <<

``
unsigned char a = 5; // 00000101
unsigned char b = a << 4;> // 01010000
``


## Dịch phải >>

Sử dụng trong bài pinHigh, pinLow dùng enum 

```
void pinHigh(pins pin){
PORTA = PORTA | (0b10000000 >> pin); 
}```