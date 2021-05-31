#include <stdio.h>

int main(void){

    FILE *fp = NULL; // 파일포인터 초기화

    fp = fopen("sample.txt","w"); // 쓰기형식으로 열기

    if( fp == NULL ){ // 파일 열기 성공 여부 판단
        printf("파일 열기 실패\n");
    }
    else{
        printf("파일 열기 성공\n");
    }

    fclose(fp); // 파일 포인터 닫기

    return 0;
}