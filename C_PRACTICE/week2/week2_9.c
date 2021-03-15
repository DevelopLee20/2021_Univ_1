#include <stdio.h>

int main(void){
    int i =0;
    do{
        scanf("%d",&i);
    }while(i<1 | i>3);

    printf("%d",i);

    return 0;
}