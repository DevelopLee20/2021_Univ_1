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
            average = i;
            break;
        }
    }

    for(int j=0; j<average; j++){
        sum += scores[j];
    }

    average = sum / average;
    printf("성적 평균 = %d\n",average);

    return 0;
}