#include <stdio.h>

void delete(int a[], int n, int loc){

    for(int i=loc; i<n; i++){
        a[i] = a[i+1];
    }

    n--;
}

int main(void){
    int n = 9; // 인덱스 최대 값
    int a[10] = {0,1,2,3,4,5,6,7,8,9}; // 임의의 크기10의 배열 선언
    int loc; // 삭제할 위치
    
    for(int i=0; i<10; i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    scanf("%d",&loc);

    delete(a, n, loc);

    for(int i=0; i<9; i++){
        printf("%d ",a[i]);
    }

    return 0;
}