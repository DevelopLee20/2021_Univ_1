#include <stdio.h>

int main(void){
    int i,sum;

    sum = 0;
    for(i = 1; i<=10; i++){
        sum += i;
    }
    printf("%d",sum);

    return 0;
}