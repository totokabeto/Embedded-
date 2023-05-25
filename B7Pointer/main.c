#include <stdio.h>

void tong(int a, int b){
    printf("Tong cua %d và %d la %d ",a,b,a+b);
}

void hieu(int a, int b){
    printf("Hieu cua %d và %d la %d ",a,b,a-b);
}
void tich(int a,int b ){
   printf("Tich cua %d và %d la %d ",a,b,a*b);
}
void thuong(int a,int b ){
   printf("Thuong cua %d và %d la %f",a,b,(float)a/b);
}
void tinhToan(int a,int b, void (*ptr)(int,int )){
    printf("Chuong trinh toan \n");
    ptr(a,b);
}
int main(int argc, char const *argv[])
{
    int i = 10; 

    double d = 15.6; 

    char c = 'A';

    void *ptr = &i; 

    printf("i = %d \n",*(int*)ptr);
    ptr = &d; 
    printf("i = %f \n",*(double *)ptr);
    ptr = &c; 
    printf("i = %c \n",*(char *)ptr);
    ptr = &tong; 

    ((void (*)(int,int))ptr)(9,16);

    char* array = "hello"; //phan vung text 

    char array1[] = "hello"; // phan vung stack 

    char* array2[]= {"Hi","hello","world"};

    printf("test: %c\n", *(*(array2+1)+3));

    int a = 15; 

    int *ptr2 = &a; 

    int **ptp = &ptr2; 

    printf("test : %d \n",**ptp);
    return 0;
}
