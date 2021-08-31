#include <stdio.h>

int main(void){

    FILE *fp = NULL; // 파일 포인터 초기화

    fp = fopen("sample.txt","w"); // sample 쓰기형식으로

    if(fp==NULL){ // 아직 NULL이면 파일 실패
        printf("파일 열기 실패\n");
    }

    else{
        printf("파일 열기 성공\n");
    }

    fputc('a',fp); // 글자쓰기
    fputc('b',fp); // 글자쓰기
    fputc('c',fp); // 글자쓰기
    fclose(fp);    // 파일 닫기

    return 0;
}