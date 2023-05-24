#include <stdio.h>
#include <stdint.h>


struct typeDate
{
    uint8_t ngay; // 1 byte + 3 byte bo nho dem 
    uint32_t thang; // 4 byte 
    uint16_t nam; // 2 byte + 2 byte bo nho dem 
};

typedef struct 
{
  uint8_t arr1[7]; // 2*3 + 1 + 1 byte bo nho dem 
  uint16_t arr2[5]; // 2 * 5 
}sizeTest;
// 18 byte 
typedef struct 
{
    uint64_t arr1[6];
    uint16_t arr2[5]; 
    uint32_t arr3[3]; 
}test;

// 64 byte 

int main(int argc, char const *argv[])
{
    struct typeDate data; 
    printf("Size : %d \n", sizeof(data));
    return 0;
}

