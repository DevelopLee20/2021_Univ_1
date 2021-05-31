#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

    FILE *fp1, *fp2;            // 파일 포인터 변수
    char a[10], b[10], c[10];   // 파일명 변수
    char buffer[1024];          // 복사할 내용 저장용 변수

    printf("repcopy ");     
    scanf("%s %s",&a, &b);  // 파일명 받는 부분

    strcpy(c,a);            // 문자열 a를 c에 복사한다.

    char *ext = strtok(c, "."); // 문자를 .을 기준으로 나눈다.
    ext = strtok(NULL, ".");    // ext에는 .뒤의 확장자명이 저장된다.

    if(strcmp(ext,"txt")){  // 확장자 명이 txt가 아니라면 이진파일을 연다.

        // 이진파일 열기, 열기실패 했을때 프로그램 종료
        if((fp1 = fopen(a,"rb")) == NULL || (fp2 = fopen(b,"wb")) == NULL){
            fprintf(stderr, "[Line 22] File Open Error");
            exit(1);
        }

        int r_count;

        // 이진파일의 데이터를 저장해간다.
        while((r_count = fread(buffer, sizeof(char), sizeof(buffer), fp1)) > 0){
            
            // 내용을 작성한다.
            int w_count = fwrite(buffer, sizeof(char) , r_count, fp2);

            // w_count와 r_count 내용이 다르다면 복사 오류
            if(w_count < 0){
                fprintf(stderr, "파일 쓰기 오류\n");
                return 1;
            }

            if(w_count < r_count){
                fprintf(stderr, "미디어 쓰기 오류\n");
                return 1;
            }
        }
    }

    else{   // 확장자명이 txt일 경우

        // 읽기형식과 쓰기형식으로 파일을 열기 실패했으면 오류 문장 출력 후 프로그램 종료
        if((fp1 = fopen(a,"r")) == NULL || (fp2 = fopen(b,"w")) == NULL){
            fprintf(stderr, "[Line 47] File Open Error");
            exit(1);
        }

        // txt파일의 한 줄씩 받아서 buffer에 복사
        while(fgets(buffer, 100, fp1) != NULL){
            fputs(buffer, fp2); // buffer 내용을 저장
        }
    }

    printf("File Copy Success!\n"); // 복사에 성공했으면 문장 출력

    fclose(fp1); // 파일 포인터 닫기
    fclose(fp2); // 파일 포인터 닫기

    return 0;
}