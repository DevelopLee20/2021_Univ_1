#include <stdio.h>

int main(void){
    int num;
    int result = 0;

    scanf("%d",&num);

    while(num > 10){
        result += num % 10;
        num = num / 10;
    }
    result += num;
    printf("합: %d",result);
}