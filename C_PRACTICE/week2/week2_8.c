#include <stdio.h>

int main(void){
    int n;
    int i = 1;

    scanf("%d",&n);

    while (i<=9){
        printf("%d*%d = %d",n,i,n*i);
        i++;
    }

    return 0;
}