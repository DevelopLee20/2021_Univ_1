#include <stdio.h>

int main(void)
{
    int a = 10;
    void *p;

    p = &a;

    // printf("%d",*p); 오류 발생
    printf("%d",*(int *)p);

    return 0;
}