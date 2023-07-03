/*
* File: string_compare.c
* Author: Le Ngoc Hau
* Date: 28/6/2023
* Description: This file to do exercise with string or arr of char
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>


//so sanh 2 chuoi
//char arr1[] = "Hello"; char arr2[] = "This is test"

typedef enum{
    SMALLER,
    EQUAL,
    BIGGER
}Compare;

struct Word{
    int length;
    char* addr;
}word;

/*
* Function: isEqual 
* Description: This function compare 2 string whether it is equal 
* Input:
*   arr1[] - an array of char
*   arr2[] - an array of char
* Output:
*   returns whether string1 == string2
*/
bool isEqual(const char arr1[], const char arr2[])
{
    uint8_t i = 0;

    while(arr1[i] == arr2[i])
    {
        if(arr1[i] == '\0') return true;
        i++;
    }
    return false;
}

/*
* Function: compare_String
* Description: This function compare 2 string
* Input:
*   arr1[] - an array of char
*   arr2[] - an array of char
* Output:
*   returns EQUAL, SMALLER or BIGGER
*/


/*
* Function: revert_string
* Description: This function revert word in string
* Input:
*   arr1[] - an array of char
* Output:
*   revert string
*/
void revert_string(const char arr1[])
{
    int string_length = 0;
    
    while(arr1[string_length] != '\0')
    {
        string_length++;
    }

    int word_length = 0;
    char arr2[string_length - 1];

    for(int index = string_length - 1; index >= 0; index--)
    {
        word_length ++ ;    
        if(arr1[index] == ' ')
        {
            for(int k = 0; k <= word_length; k++)
            {
                arr2[string_length - (index + (word_length - k))] = arr1[index + 1 + k];
            }
            word_length = 0;
        }
        if(index == 0)
        {
            for(int k = 0; k <= word_length; k ++)
            {
                arr2[string_length - (index + (word_length - k))] = arr1[index + k];
            }
            break;
        }
    }
    
    for(int i = 0; i < string_length; i++)
    {
        printf("%c", arr2[i]);
    }
}

int main(int argc, char const *argv[])
{
    const char arr1[] = "Thai exporters are halving the time it takes to deliver durian to China, from 8 days to four days, in order to better compete with Vietnam over the pungent fruit.";
    const char arr2[] = "Hello World Hau";
    const char arr3[] = "Hello World";

    //printf("test: %d\n", compare_String(arr2, arr3));

    revert_string(arr1);

    return 0;
}