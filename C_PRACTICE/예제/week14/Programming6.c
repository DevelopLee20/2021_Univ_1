#include <stdio.h>

#define SET_BIT(n, pos) ((n) |= (1 << (pos)))
#define CLR_BIT(n, pos) ((n) &= (~(1) << (pos)))
#define GET_BIT(n, pos) ((n) & (1 << pos)) >> pos

int main(void){

    int n = 0x808081;

    printf("%d\n", GET_BIT(n, 1));

    SET_BIT(n,1);

    printf("%d\n", GET_BIT(n, 1));

    CLR_BIT(n,1);

    printf("%d\n", GET_BIT(n, 1));

    return 0;
}