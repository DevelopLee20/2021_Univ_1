#include <stdio.h>
#define SIZE 10

int main(void){
    char ans1;
    int ans2,ans3, i;
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
            scanf("%d %d",&ans2, &ans3);

            if (ans2 <= 0 || ans2 > SIZE){
                printf("1부터 10사이의 숫자를 입력하시오\n");
                continue;
            }

            if (seats[ans2-1] == 0){
                seats[ans2-1] = 1;
                printf("예약되었습니다.\n");
            }
            else{
                printf("이미 예약된 자리입니다.\n");
            }

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