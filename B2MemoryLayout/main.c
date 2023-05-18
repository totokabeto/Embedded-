#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char const *argv[])
{
    uint8_t *ptr = (uint8_t*) malloc(sizeof(uint8_t)*7);
    for (int i = 0; i < 7; i++)
    {
         ptr[i]= i; 
    }
    for (int i = 0; i < 7; i++)
    {
        /* code */
        printf("Gia tri cua mang la %d \n ", ptr[i]);
    }
    free(ptr);
    
    
    return 0;
}
