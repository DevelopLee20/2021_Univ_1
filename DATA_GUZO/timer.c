#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main(void){
    clock_t start, end;

    start = clock();
    // 코드 작성
    end = clock();

    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%.4lf",duration);
}