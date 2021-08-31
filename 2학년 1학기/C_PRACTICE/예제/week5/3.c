#include <stdio.h>

int main(void)
{
    int i = 3000;
    int *p;

    p = &i;

    printf("%d\n",i);
    printf("%u\n",&i);
    printf("%u\n",p);
    printf("%d\n",*p);

    return 0;
}