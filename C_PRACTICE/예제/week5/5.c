#include <stdio.h>

int main(void)
{
    int *v;
    int a = 10;
    v = &a;

    // v = *p++ // p = v 후 p++
    // v = (*p)++ // p = v 후 값++
    // v = *++p // p 증가 후 p의 값을 v에 대입
    // v = ++*p // p 값을 증가 후 v에 대입

    return 0;
}