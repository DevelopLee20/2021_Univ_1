#include <stdio.h>

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

int main(void){
    int in;
    scanf("%d",&in);
    int chk = fibo_iter(in);
    printf("%d",chk);
    return 0;
}