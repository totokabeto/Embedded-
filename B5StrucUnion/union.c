#include <stdio.h> 
#include <stdint.h> 
#include <string.h>

typedef union 
{
    char test1[6];
    char test2[3];
}typeData;

typedef union 
{
    uint8_t test1[5];
    uint8_t test2[3]; 
}typeTest;
 // kích thước và 5 byte 
int main(int argc, char const *argv[])
{
    /* code */
    typeData data;

    strcpy(data.test1, (char*)"Hello");

    strcpy(data.test2, (char*)"Hi");
    
  /* printf("dia chi cua union : %p \n", &data);
      printf("dia chi cua union : %p \n", &data.a);
        printf("dia chi cua union : %p \n", &data.b);
          printf("dia chi cua union : %p \n", &data.c);
    data.a = 12; 
    data.b = 27; 
    data.c = 35; */
    printf("test = %s\n ",data.test1);
    
    // bản chất sẽ là Hi llo nhưng hàm printf chỉ quét đến chỗ có null thì sẽ dừng không quét nữa 


    for (int i = 0; i < 6; i++)
    {
        printf("%c ", data.test1[i]);
    }
    
    return 0;
}

