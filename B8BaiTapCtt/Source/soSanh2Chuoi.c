#include <stdio.h>
#include <stdbool.h> 
#include <stdint.h> 


bool isEqual(const char arr1[], const char arr2[]){
int i = 0;
while (arr1[i] == arr2[i])
{
    if(arr1[i] == '\0'){
        return true; 
    }
    i++;
}
return false;
}


int main(int argc, char const *argv[])
{
    char arr1[] ={"Khanh dep traia"};
    char arr2[] ={"Khanh dep trai"};

    printf("ket qua so sanh %d",isEqual(arr1,arr2));
    return 0;
}
