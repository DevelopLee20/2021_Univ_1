#include <stdio.h>
#include <string.h>

int main(void){
    float result = 200;
    int garo, sero, cnt;
    char namu;

    scanf("%d %d %c %d",&garo,&sero,&namu,&cnt);

    if (garo*sero > 750)
        result += 50;
    if (namu == 'M')
        result += 150;
    else if (namu == 'O')
        result += 125;
    result += cnt*30;
    result += result/10;

    printf("총 제작비: %0.2f달러",result);

    return 0;
}