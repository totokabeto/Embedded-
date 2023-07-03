#include <stdio.h>
#include <stdint.h>

void swap(uint8_t *a, uint8_t *b){
uint8_t temp; 
temp = *a; 
*a = *b; 
*b = temp; 
}

void sortList(uint8_t array[],uint8_t size){
for (uint8_t i = 0; i < size-1; i++)
{
   for ( uint8_t j = i+1;  j < size; j++)
   {
    if(array[i]> array[j]){
        swap(&array[i],&array[j]);
    }
   }
}
}
void printArray(uint8_t array[],uint8_t size){
for (uint8_t i = 0; i < size ; i++)
{
    printf("%d \n",array[i]);
}
}
void demSoLan(uint8_t array[], uint8_t size){
for (int i = 0; i < size;i++){
    int count = 1; 
    if (i> 0 && array[i] == array[i-1]){
        continue;
    }
    printf("so %d xuat hien: ", array[i]);
    for(int j = i+1; j < size; j++){
        if (array[j] == array[i]){
            count++;
        }
    }
    printf("%d lan\n",count);
}
}
typedef enum{
    DAU_CACH, 
    CHU_SO
}TypeMath; 


void daoChuoi(const char array[], uint8_t size){
    char temp[100]; 
    char chu[100];
    int i = 0; 
    while (array[i] != ' '){
        temp[i] = array[i]; 
        i++; 
        printf(" temp : %c \n ",temp[i]);
    }
}

int main(int argc, char const *argv[])
{
    uint8_t array1[] = {1,3,4,5,6,7,8,2,3,4,5,6,7};
    char array2[] = "Thai exporters are halving the time it takes to deliver durian to China, from 8 days to four days, in order to better compete with Vietnam over the pungent fruit.";
    uint8_t size = sizeof(array1)/sizeof(uint8_t);
    uint8_t size2 = sizeof(array2)/sizeof(char); 
   // sortList(array1,size);
  //  printArray(array1,size);
   // demSoLan(array1,size);
   daoChuoi(array2,size2);
    return 0;

}
