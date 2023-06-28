#include <stdio.h>
#include <stdint.h>

typedef enum{
    NUMBER, 
    OPERATOR,
}TypeMath;

typedef struct{
    TypeMath key; 
    union 
    {
    uint16_t number;
    char operator; 
    }value;
    
}typeMaths;


void stringtoDec(char input[], typeMaths output[]){

    uint16_t number = 0; 
    uint8_t i = 0; 

while(*input != '\0')
{

   if(*input >= '0' && *input <= '9'){
        uint8_t temp = *input - '0';
        number = 10 * number + temp; 
        input++; 
        continue;
   } else if(*input == '+' || *input == '-' || *input == '*' || *input == '/'){
                output[i].key = OPERATOR;
                output[i].value.operator = *input;
                i++;
                input++; 
                continue;
    } else{
        if (number != 0){
            output[i].key = NUMBER;
            output[i].value.number = number;
            number = 0;
            i++;
        }
    }
    input++;
}
    output[i].key = NUMBER; 
    output[i].value.number = number; 
}

// tach so va chuyen tu char sang dec 
int tong(int a, int b){
    printf("Tong cua %d và %d la %d \n",a,b,a+b);
    return a + b; 
}

int hieu(int a, int b){
    printf("Hieu cua %d và %d la %d \n ",a,b,a-b);
    return a - b; 
}
int tich(int a,int b ){
   printf("Tich cua %d và %d la %d \n ",a,b,a*b);
   return a*b; 
}
float thuong(int a,int b ){
   printf("Thuong cua %d và %d la %f \n",a,b,(float)a/b);
   return a/b; 
}
int tinhToan(int a,int b, int (*ptr)(int,int)){
    printf("Chuong trinh toan \n");
    ptr(a,b);
}
// dung scanf 

void tinhTichChuoi(typeMaths arr[], int arraySize){
for (int i = 0; i < arraySize; i++)
    {
        if(arr[i].value.operator == '*' ){
            arr[i+1].value.number = tinhToan(arr[i-1].value.number,arr[i+1].value.number,tich);
            arr[i-1].value.number = arr[i+1].value.number;
            arr[i].value.operator = ' ';
            continue;
            }
}
}
void tinhThuongChuoi(typeMaths arr[], int arraySize){
for (int i = 0; i < arraySize; i++)
    {
        if(arr[i].value.operator == '/' ){
            arr[i+1].value.number = tinhToan(arr[i-1].value.number,arr[i+1].value.number,thuong);
            arr[i-1].value.number = arr[i+1].value.number;
            arr[i].value.operator = ' ';
            continue;
            }
}
}

void tinhHieuChuoi(typeMaths arr[], int arraySize){
for (int i = 0; i < arraySize; i++)
    {
        if(arr[i].value.operator == '-' ){
            arr[i+1].value.number = tinhToan(arr[i-1].value.number,arr[i+1].value.number,hieu);
            arr[i-1].value.number = arr[i+1].value.number;
            arr[i].value.operator = ' ';
            continue;
            }
}
}
void tinhTongChuoi(typeMaths arr[], int arraySize){
    for (int i = 0; i < arraySize; i++)
    {      
            if (arr[i].value.operator == '+') {
            
            arr[i+1].value.number = tong(arr[i+1].value.number,arr[i-1].value.number);
            arr[i-1].value.number = arr[i+1].value.number;
            arr[i].value.operator = ' ';
            continue;
    }
}
}

void tinhToanChuoi(typeMaths arr[], int arraySize){
    tinhTichChuoi(arr,arraySize);
    tinhThuongChuoi(arr,arraySize);
    tinhTongChuoi(arr,arraySize);
    tinhHieuChuoi(arr,arraySize);
}

void xuatChuoi(typeMaths arr[], int arraySize){
  for (int i = 0; i < arraySize; i++)
    {
        if(arr[i].key == NUMBER){
            printf("type : NUMBER, value : %d\n",arr[i].value.number);
        }else {
            printf("type : OPERATOR, operator : %c\n",arr[i].value.operator);
        }
    }
}
int main(int argc, char const *argv[])
{
    char arr1[] ="123 * 4 + 6 + 3 + 2";

    typeMaths ouput[9];

    stringtoDec(arr1,ouput);

    tinhToanChuoi(ouput,20);

    return 0;
}
