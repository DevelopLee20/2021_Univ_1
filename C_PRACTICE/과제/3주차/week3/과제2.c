#include <stdio.h>
#define SIZE 10

int main(void){
    char ans1;
    // 2사람을 동시에 예약 받기 위해서 ans3 변수를 추가하였다.
    int ans2,ans3, i;
    // seats 배열을 0으로 초기화
    int seats[SIZE] = {0};

    while(1){
        printf("좌석을 예약 하시겠습니까?(y 또는 n) ");
        scanf("%c",&ans1);
        if (ans1=='y'){
            printf("----------------------\n");
            printf(" 1 2 3 4 5 6 7 8 9 10\n");
            printf("----------------------\n");
            for(i=0; i<SIZE; i++){
                printf(" %d",seats[i]);
            }
            printf("\n");
            printf("몇 번째 좌석을 예약 하시겠습니까 ");
            // 입력받는 사람을 한명 더 늘린다.
            scanf("%d %d",&ans2, &ans3);

            if (ans2 <= 0 || ans2 > SIZE){
                printf("1부터 10사이의 숫자를 입력하시오\n");
                continue;
            }

            // 첫번째 사람의 예약
            if (seats[ans2-1] == 0){
                seats[ans2-1] = 1;
                printf("예약되었습니다.\n");
            }
            else{
                printf("이미 예약된 자리입니다.\n");
            }

            // 두번째 사람의 예약
            if (seats[ans3-1] == 0){
                seats[ans3-1] = 1;
                printf("예약되었습니다.\n");
            }
            else{
                printf("이미 예약된 자리입니다.\n");
            }

        }
        else if (ans1 =='n'){
            return 0;
        }
    }
    return 0;
}