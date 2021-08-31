#include <stdio.h>

int recursive(int n){
    if ( n <= 0 )
      return 0;
    else
      return recursive(n-3) + n;
}

void main(void){
    int a = recursive(20);
    printf("%d",a);
}