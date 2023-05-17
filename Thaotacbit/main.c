#include <stdio.h>
#include <stdint.h>

void ReadByte(uint8_t byte){                                                
uint8_t temp = 0b10000000; 
uint8_t b; 
printf("0b");
for (int i = 0; i < 8; i++)
{
b = (temp & byte);// 1000000 & 10010001 = 1000000 => 10000000 & 00100010 = 0000000
if (b == 00000000){
    printf("0");
} else {
    printf("1");
}
byte <<= 1;
}
}
int main(int argc, char const *argv[])
{
    /* code */
    uint8_t test = 0b10011001;
    ReadByte(test);
    return 0;
}
