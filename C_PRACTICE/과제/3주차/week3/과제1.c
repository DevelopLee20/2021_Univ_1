#include <stdio.h>
#define STUDENTS 5

int main(void){
    int scores[STUDENTS];
    int sum = 0;
    int average;

    for(int i=0; i<STUDENTS; i++){
        printf("학생들의 성적을 입력하시오: ");
        scanf("%d",&scores[i]);

        if (scores[i] < 0){
            // 만약 입력값이 0보다 작으면 average 값에 i를 대입하고 종료한다.
            average = i;
            break;
        }
    }

    // average = i 이므로 i번째 까지만 반복해서 더하는 것과 같다.
    for(int j=0; j<average; j++){
        sum += scores[j];
    }

    // average = i 이므로, average = sum / i와 같다.
    average = sum / average;
    // 결과값 출력
    printf("성적 평균 = %d\n",average);

    return 0;
}