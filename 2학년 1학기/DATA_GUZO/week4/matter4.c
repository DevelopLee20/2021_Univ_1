#include <stdio.h>

int gcd(int u, int v){
    if (u == v)
        return u;
    if (u > v)
        return gcd(u-v,v);
    else
        return gcd(u,v-u);
}

int main(void){
    int u, v;
    scanf("%d %d",&u, &v);

    int result = gcd(u,v);

    printf("%d",result);

    return 0;
}