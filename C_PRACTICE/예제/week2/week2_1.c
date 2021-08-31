#include <stdio.h>

int main(void){
    float x = 1.234567890123456789;
    double y = 1.234567890123456789;

    printf("%f",x);
    printf("%lf",y); // 정확도는 double형이 높다.

    return 0;
}