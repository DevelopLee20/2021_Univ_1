#include <stdio.h>

int main(void){
    int a = 10;
    int b = 20;
    int *p1;
    int *p2;

    p1 = &a;

    printf("1. %d %d %d %d\n",a,b,*p1,*p2);

    p2 = &b;

    printf("2. %d %d %d %d\n",a,b,*p1,*p2);    

    b = *p1;

    printf("3. %d %d %d %d\n",a,b,*p1,*p2);

    *p2 = 20;

    printf("4. %d %d %d %d\n",a,b,*p1,*p2);

    *p1 = *p2;

    printf("5. %d %d %d %d\n",a,b,*p1,*p2);

    p2 = p1;

    printf("6. %d %d %d %d\n",a,b,*p1,*p2);

    *p2 = 10;

    printf("7. %d %d %d %d\n",a,b,*p1,*p2);

    return 0;
}