#include <stdio.h> // 표준입출력 라이브러리
#define SIZE 3     // SIZE는 3을 대신함

struct student  // 구조체 student 선언
{
    int number;
    char name[20];
    double grade;
};

int main(void){
    struct student list[SIZE];  // student 구조체를 list 변수에 저장
    int i;

    // 반복을 통해서 학생정보를 입력받음
    for(i=0; i<SIZE; i++){
        printf("학번을 입력하시오: ");
        scanf("%d", &list[i].number);
        printf("이름: ");
        scanf("%s", &list[i].name);
        printf("학점(실수): ");
        scanf("%d", &list[i].grade);
        printf("\n");
    }

    // 반복을 통해서 학생정보를 출력함
    for(i=0; i<SIZE; i++){
        printf("학번: %d, 이름: %s, 학점: %f\n", list[i].number, list[i].name, list[i].grade);
    }

    return 0;
}