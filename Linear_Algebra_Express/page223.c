#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

double det(double (*A)[N], int n);
void cramer(double (*A)[N], double C[N], int n, int c);

void main(void){
    int i=0, j=0;
    int n;
    double A[N][N] = {0,};
    double C[N] = {0,};

    printf(" 크레머의 규칙을 이용한 선형방정식 계산 프로그램\n");
    printf("선형방정식의 최대 차수를 입력하세요: ");
    scanf("%d",&n);

    printf("\n");

    printf("선형방정식의 수식을 입력하세요.\n");

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d 번째 선형방정식 x%d 의 값: ",i+1, j+1);
            scanf("%lf",&A[i][j]);
        }
    }
    printf("\n");

    printf("선형방정식의 결과 값을 입력하세요.\n");

    for(i=0; i<n; i++){
        printf("%d 번째 선형방정식의 결과 값: ",i+1);
        scanf("%lf", &C[i]);
    }

    printf("\n 입력한 선형방정식의 행렬= \n\n");
    
    for(i=0; i<n; i++){
        printf("|\t");

        for(j=0; j<n; j++){
            printf("%.lf x%d\t", A[i][j], j+1);
        }
        printf("=\t");
        printf("%.lf\t",C[i]);
        printf("\n");
    }
    printf("\n");

    printf("입력한 선형방정식의 행렬식 값\n");
    printf("Det(A) = %.lf\n\n", det(A,n));
    printf("입력한 선형방정식의 해답\n");

    for(i=1; i<n+1; i++){
        cramer(A,C,n,i);
    }
    printf("\n\n");
}

double det(double (*A)[N], int n){
    int i, j, k, y;
    double det_a = 0;
    double temp[N][N];

    if (n!=1){
        for(i=0; i<n; i++){
            for(j=1; j<n; j++){
                y = 0;

                for(k=0; k<n; k++){
                    if (k!=i){
                        temp[j-1][y++] = *(A[0]+j*N+k);
                    }
                }
            }
            det_a = det_a + *(A[0]+i) * (pow(-1,i)) * det(temp,n-1);
        }return det_a;
    }else return *A[0];
}

void cramer(double (*A)[N], double C[N], int n, int c){
    int i=0, j=0;

    double temp[N][N] = {0,};

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            temp[i][j] = A[i][j];
        }
    }

    for(i=0; i<n; i++){
        for(j=c-1; j<c; j++){
            temp[i][j] = C[i];
        }
    }
    printf("x%d = %.f \t",c, (det(temp,n) / det(A,n)) );
}