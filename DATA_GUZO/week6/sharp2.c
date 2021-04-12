#include <stdio.h>

int main(void){
    int a;
    int b;
    int c;

    int *p;
    int *q;
    int *r;

    p = &a;
    q = &b;
    r = &c;

    printf("p: %d\n",p);
    printf("q: %d\n",q);
    printf("r: %d\n",r);

    *p = 10;
    *q = 20;
    *r = 30;

    p = &c;
    q = &a;
    r = &b;

    printf("*p -> c: %d\n",*p);
    printf("*q -> a: %d\n",*q);
    printf("*r -> b: %d\n",*r);

    printf("a: %d\n",a);
    printf("a 주소: %d\n",&a);
    printf("b: %d\n",b);
    printf("b 주소: %d\n",&b);
    printf("c: %d\n",c);
    printf("c 주소: %d\n",&c);

    return 0;
}