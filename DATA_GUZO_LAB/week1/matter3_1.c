#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fun_1(int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += 1;
    }
    return sum;
}

int fun_2(int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            sum += 1;
    }
    return sum;
}

int fun_3(int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; j++)
                sum += 1;
        }
    }
    return sum;
}

void main(void){
    clock_t start, end;

    start = clock();
    fun_3(500);
    end = clock();

    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%.4lf",duration);
}