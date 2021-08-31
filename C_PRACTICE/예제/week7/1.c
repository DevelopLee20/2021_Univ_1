#include <stdio.h>

int main(void)
{
    int a[5] = {1,2,3,4,5};
    int (*pa)[5];
    int *b[5];

    printf("a: %d\n",&b[0]);

    pa = &a;

    for(int i=0; i<5; i++){
        printf("%d ",(*pa)[i]);
    }

    return 0;
}