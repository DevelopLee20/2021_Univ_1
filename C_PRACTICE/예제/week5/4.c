#include <stdio.h>

int main(void)
{
    int i = 10;
    int *p;

    p = &i;
    printf("%d\n",i);

    *p = 20;
    printf("%d\n",i);

    return 0;
}