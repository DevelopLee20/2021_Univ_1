#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

struct student{ // 구조체 선언
    int number;
    char name[20];
    double gpa;
};

int main(void){

    struct student table[SIZE] = { // 구조체 배열 선언
        {1, "Kim", 3.99},
        {2, "Min", 2.68},
        {3, "Lee", 4.01}
    };

    struct student s; // 구조체 s 선언
    
    FILE *fp = NULL;  // 파일 포인터 초기화
    int i;

    // 이진파일 쓰기형식으로 파일 열기
    if((fp=fopen("student.dat", "wb"))==NULL){
        fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
        exit(1);
    }

    // 이진파일 쓰기
    fwrite(table, sizeof(struct student), SIZE, fp);
    fclose(fp); // 파일 포인터 닫기

    // 이진 파일 읽기형식으로 파일 열기
    if((fp=fopen("student.dat","rb"))==NULL){
        fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.\n");
        exit(1);
    }

    // 내용 출력
    for(i=0; i<SIZE; i++){
        fread(&s, sizeof(struct student),1, fp);
        printf("학번 = %d, 이름 = %s, 평점 = %f\n", s.number, s.name, s.gpa);
    }

    fclose(fp); // 파일 포인터 닫기

    return 0;
}