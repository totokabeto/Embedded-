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
Qúa trình tiếp theo là quá trình compiler chuyển từ file main.i sang file main.s hay còn gọi là file assembly code
Tiếp đó là quá trình Assembler chuyển thành file main.o hay main.obj tại bước này các file thư việc của âm thanh và hình ảnh sẽ được thêm vào 
Bước cuối cùng là Linker chuyển thành dạng file main.exe [đổi với Windows] để người dùng có thể run 
# Bài 2 
# Bài 3 
# Bài 4
