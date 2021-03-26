#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hanoi(int n, int A, int B, int C){
    if (n==1){
        return 0;
    }
    hanoi(n-1,A,C,B);
    hanoi(n-1,B,C,A);
}

void main(void){
    clock_t start, end;

    start = clock();
    hanoi(35,1,2,3);
    end = clock();

    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%.4lf",duration);
}