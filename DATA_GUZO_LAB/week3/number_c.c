#include <stdio.h>

int sum(int n){
    if ( n <= 0 )
      return 0;
    else
      return sum(n-1) + n;
}

int main(void){
    int in;
    scanf("%d",&in);
    int pri = sum(in);
    printf("%d",pri);

    return 0;
}