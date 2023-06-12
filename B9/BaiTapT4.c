#include <stdio.h>
#include <stdint.h>

typedef enum{
    NUMBER, 
    OPERATOR,
}TypeMath;

typedef struct{
    TypeMath key; 
    union 
    {
    uint16_t number;
    char operator; 
    }value;
    
}typeMaths;


void stringtoDec(char input[], typeMaths output[]){

    uint16_t number = 0; 
    uint8_t i = 0; 

while(*input != '\0'){

   if(*input >= '0' && *input <= '9'){
        uint8_t temp = *input - '0';
        number = 10 * number + temp; 
        input++; 
        continue;
   } else if(*input == '+' || *input == '-' ||
            *input == '*' || *input == '/'){
                output[i].key = OPERATOR;
                output[i].value.operator = *input;
                i++;
                input++; 
                continue;
    } else{
        if (number != 0){
            output[i].key = NUMBER;
            output[i].value.number = number;
            number = 0;
            i++;
        }
    }
    input++;
}
    output[i].key = NUMBER; 
    output[i].value.number = number; 
}

// tach so va chuyen tu char sang dec 

// dung scanf 


int main(int argc, char const *argv[])
{
    char arr1[] ="8 + 4 + 3 + 2";
    typeMaths ouput[14];
    
    stringtoDec(arr1,ouput);

 
    return 0;
}
