#include <stdio.h>

int isPrime(int n, int num){
    if (n==num) // n = num 이 되면 소수라고 판단한다.
        return 1;
    if(n%num == 0)
        return 0;
    else
        return isPrime(n,num+1); // 판단할 num값을 하나씩 증가시켜서 소수인지 아닌지 체크한다.
}

int main(void){
    int n;
    scanf("%d",&n);
    printf("%d",isPrime(n,2));

    return 0;   
}