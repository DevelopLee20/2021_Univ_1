#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibo_rec(int n){
    if ( n <= 0 )
      return 0;
    else if ( n == 1 )
      return 1;
    else
      return fibo_rec(n-1) + fibo_rec(n-2);
}

int fibo_iter(int n){
    int one = 0;
    int two = 1;
    int next;
    for (int i=0; i<n; i++){
        next = one + two;
        one = two;
        two = next;
    }
    return one;
}
void main(void){
    clock_t start, end;

    start = clock();
    fibo_iter(45);
    end = clock();

    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%.4lf",duration);
}