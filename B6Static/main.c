#include <stdio.h>


extern int count;

void test(){
    static int a = 10; 
    printf("a = %d\n",a); 
    a++; 
}
int main(int argc, char const *argv[])
{
    test();
    test();
    test();
    printf("%d ",count);
    return 0;
}
