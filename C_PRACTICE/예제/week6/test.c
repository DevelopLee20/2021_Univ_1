#include <stdio.h>

int kkk(int *a){
    for(int i=0; i<5; i++){
        printf("%d ",a[i]);
    }
}

int main(void){
    int a[] = {10,20,30,40,50};

    kkk(a);

    return 0;
}