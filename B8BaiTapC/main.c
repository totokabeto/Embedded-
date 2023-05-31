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
    for(int j = i+1; j < size; j ++){
        if (array[j] == array[i]){
            count++;
        }
    }
    printf("%d lan\n",count);
}
}


int main(int argc, char const *argv[])
{
    uint8_t array1[] = {3,1,4,2,5,4,9,15,12};
    uint8_t size = sizeof(array1);
    sortList(array1,size);
    printArray(array1,size);
    demSoLan(array1,size);
     return 0;

}
