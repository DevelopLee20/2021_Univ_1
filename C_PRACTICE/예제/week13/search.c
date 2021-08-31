#include <stdio.h>
#include <string.h>

int main(void){

    FILE *fp;           // 파일 포인터 선언
    
    char fname[128];    
    char buffer[256];   // 버퍼 선언
    char word[256];
    int line_num = 0;

    printf("입력 파일 이름을 입력하시오: ");
    scanf("%s", fname); // 파일명 입력

    printf("탐색할 단어를 입력하시오: ");
    scanf("%s", word);  // 찾을 단어 입력

    if((fp==fopen(fname, "r"))==NULL){   // fopen한 값이 NULL 이면 파일 오픈 실패
        fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname);
        exit(1);
    }

    while(fgets(buffer, 256, fp)){  // 오픈에 성공했다면, fp의 내요을 buffer에 복사
        if(strstr(buffer, word)){   // 문자열 검색
            printf("%s: %d 단어 %s이 발견되었습니다.\n", fname, line_num, word);
        }
    }

    fclose(fp); // 파일 포인터 닫기

    return 0;
}