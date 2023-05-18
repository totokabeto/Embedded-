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
    HIGH,
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
    PORTA = PORTA | (0b1000000 >> pin); 


    switch (pin)
    {
    case PIN0:
        /* code */
        PORTA = 0b10000000;
        break;
     case PIN1:
        /* code */
        PORTA = 0b01000000;
        break;
         case PIN2:
        /* code */
        PORTA = 0b00100000;
        break;
         case PIN3:
        /* code */
        PORTA = 0b00010000;
        break;
         case PIN4:
        /* code */
        PORTA = 0b00001000;
        break;
          case PIN5:
        /* code */
        PORTA = 0b00000100;
        break;
          case PIN6:
        /* code */
        PORTA = 0b00000100;
        break;
          case PIN7:
        /* code */
        PORTA = 0b00000001;
        break;
    default:
        break;
    }
}

void pinLow(pins pin){
PORTB = PORTB & ~(0b10000000 >> pin);
}


int main(int argc, char const *argv[])
{
    /* code */
    pinHigh(PIN1);
    pinLow(PIN2);
   // ReadByte(PORTA);

    ReadByte(PORTB);
    return 0;
}
