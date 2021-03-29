#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

// random 함수
void getMat(int array[MAX][MAX], int n){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int random = (rand()%9) +1;
            array[i][j] = random;
        }
    }
}

// 행렬의 곱을 구하는 알고리즘
void mult(int A[MAX][MAX], int B[MAX][MAX],int C[MAX][MAX], int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}

// 행렬을 출력하는 함수
void printMat(int array[MAX][MAX], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    printf("-------\n");
}

int main(void){
    clock_t start, end;

    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    int n = 50;

    getMat(A, n);
    getMat(B, n);

    start = clock();
    mult(A, B, C, n);
    end = clock();

    printMat(A, n);
    printMat(B, n);
    printMat(C, n);

    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%.4lf",duration);

    return 0;
}