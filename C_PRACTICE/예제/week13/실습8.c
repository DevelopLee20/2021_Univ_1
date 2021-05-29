#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fp1, *fp2;            // 파일 포인터 초기화
    char file1[100], file2[100];
    char buffer[100];

    printf("원본 파일 이름: ");
    scanf("%s", file1);

    printf("복사 파일 이름: ");
    scanf("%s", file2);

    if((fp1 = fopen(file1, "r")) == NULL){ // 읽기형식으로 파일 열기
        fprintf(stderr, "원본 파일 %s을 열 수 없습니다.\n", file1);
        exit(1);
    }

    if((fp2 = fopen(file2, "w")) == NULL){ // 읽기형식으로 파일 열기
        fprintf(stderr, "복사 파일 %s을 열 수 없습니다.\n", file2);
        exit(1);
    }

    while(fgets(buffer, 100, fp1) != NULL){ // buffer에 fp1 내용이 줄 단위로 저장됨 NULL이면 저장 안됨
        printf("1");
        fputs(buffer, fp2); // 버퍼를 fp2에 복사함
    }
    fclose(fp1); // 파일 포인터 닫기
    fclose(fp2); // 파일 포인터 닫기

    return 0;
}