#include <stdio.h>

int addEven(int n){
    if ( n == 0 )
      return 0;
    if ( n % 2 == 1 )
      n = n - 1;
    return addEven(n-2) + n;
}

int main(void){
    int in;
    scanf("%d",&in);
    int pri = addEven(in);
    printf("%d",pri);
    return 0;
}