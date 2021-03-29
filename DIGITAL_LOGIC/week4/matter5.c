#include <stdio.h>
#define MAX 15

int count(int n){
    if (n == 0)
        return 0;
    else
        return 1 + count(n/10); // 매 시행마다 10을 나누어서 자리수를 하나씩 줄인다.
}

int main(void){
    int n;
    scanf("%d",&n);

    printf("%d",count(n));

    return 0;
}