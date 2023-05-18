#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
uint8_t PORTA = 0b00000000; 
uint8_t PORTB = 0b11111111;


typedef enum{
PIN0,
PIN1,
PIN2,
PIN3,
PIN4,
PIN5,
PIN6,
PIN7
}pins; 


typedef enum {
    LOW,
    HIGH
}s_status; 

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

void pinHigh(pins pin){
PORTA = PORTA | (0b10000000 >> pin); 
}

void pinLow(pins pin){
PORTA = PORTA & ~(0b10000000 >> pin);
}

void digitalWrite(pins pin, s_status status){
    if (status == 0)
    {
    pinLow(pin);
    } else 
    {
     pinHigh(pin);
    }
    
}
int main(int argc, char const *argv[])
{
    /* code */
   

    digitalWrite (PIN3,HIGH);
    digitalWrite (PIN6,HIGH);

    digitalWrite (PIN6,LOW);

    ReadByte(PORTA);
    return 0;
}
