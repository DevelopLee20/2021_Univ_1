#include <stdio.h>

int main(void){

    FILE *fp = NULL; // 파일 포인터 초기화
    int c;

    fp = fopen("sample.txt","r");

    if(fp==NULL){
        printf("파일 열기 실패\n");
    }
    
    else{
        printf("파일 열기 성공\n");
    }

    while(!feof(fp)){ // End Of File 까지 글자를 읽음
        c=fgetc(fp);
        putchar(c); // 문자를 출력
    }

    fclose(fp); // 파일 포인터 닫음

    return 0;
}