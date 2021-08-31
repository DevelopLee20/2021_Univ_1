#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void){
    int prices[SIZE] = {0};
    // 최소값을 최대값으로 변수명을 max로 변경하였다.
    int i, max;
    
    printf("------------------------------\n");
    printf("1  2  3  4  5  6  7  8  9  10\n");
    printf("------------------------------\n");

    // 랜덤으로 사용할 시드를 시간을 기준으로 설정한다.
    srand((unsigned)time(NULL));
    
    for(i=0; i<SIZE; i++){
        prices[i] = (rand()%100) + 1;
        printf("%-3d",prices[i]);
    }
    printf("\n\n");

    // 첫번째 값을 초기 최대값으로 설정
    max = prices[0];

    // max보다 값이 크면 max값을 변경해준다.
    for(i=1; i<SIZE; i++){
        if(prices[i] > max){
            max = prices[i];
        }
    }

    printf("최대값은 %d입니다.\n",max);
    
    return 0;
}