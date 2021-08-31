#include <stdio.h>

int main(void)
{
    int i = 10;
    double f = 12.3;
    int *pi, *pf;

    pi = &i;
    pf = &f;

    printf("%p %p\n",pi,&i);
    printf("%u %u\n",pf,&f);

    return 0;
}