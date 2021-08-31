// 실습 2
#include <stdio.h>
#define SQUARE(x) ((x) * (x))

int main(void){
    
    int x = 2;

    printf("%d\n", SQUARE(x));
    printf("%d\n", SQUARE(3));
    printf("%f\n", SQUARE(1.2));
    printf("%d\n", SQUARE(x+3));
    printf("%d\n", 100/SQUARE(x));
    printf("%d\n", SQUARE(++x));

    return 0;
}