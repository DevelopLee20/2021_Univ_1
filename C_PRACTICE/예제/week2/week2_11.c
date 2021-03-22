#include <stdio.h>

int get_integer(void);
int combination(int n, int r);
int factorial(int n);

int main(void){
    int a,b;

    a = get_integer();
    b = get_integer();

    printf("%d %d %d",a,b,combination(a,b));

    return 0;
}

long combination(int n, int r){
    return (factorial(n)/factorial(r) * factorial(n-r));
}

int get_integer(void){
    int n;
    scanf("%d",&n);

    return n;
}

long factorial(int n){
    int i;
    long result = 1;

    for(i=1; i<=n; i++){
        result *= i;
    }

    return result;
}