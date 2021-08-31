#include <stdio.h>

// malloc 동적할당을 사용하기 위한 라이브러리
#include <stdlib.h> 

int main(void){

    // 2차원 배열 동적할당
    int** table = (int**)malloc(5*sizeof(int*));
    
    // 동적 배열에 그림과 같이 대입한다.
    for(int i=0; i<5; i++){
        table[i] = (int*)malloc(sizeof(int)*i+1);
        for(int j=0; j<=i; j++){
            table[i][j] = j+1;
        }
    }

    // 동적 배열을 요소 하나하나 출력한다.
    for(int i=0; i<5; i++){
        for(int j=0; j<=i; j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

    return 0;
}