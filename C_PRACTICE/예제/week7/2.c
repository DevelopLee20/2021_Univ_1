#include <stdio.h>

int main(void)
{
    int m[3][3] = {10,20,30,40,50,60,70,80,90};

    printf("%p\n",m[6]);
    printf("%p\n",&m[2][0]);
}