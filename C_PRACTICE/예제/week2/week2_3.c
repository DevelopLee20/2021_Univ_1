#include <stdio.h>

int main(void){
    float x = 1.23456e-38;
    float y = 1.23456e-40;
    float z = 1.23456e-46;

    printf("%e\n",x);
    printf("%e\n",y);
    printf("%e\n",z);

    return 0;
}