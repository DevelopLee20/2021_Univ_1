#include <stdio.h>

int main(void){
    
    char str[30] = "C language is easy";
    int i = 0;

    while( str[i] != 0 ){   // NULL or 0을 보면 종료
        i++;                // 문자열 길이 저장
    }

    printf("문자열은 %s의 길이는 %d입니다.\n", str, i);

    return 0;
}