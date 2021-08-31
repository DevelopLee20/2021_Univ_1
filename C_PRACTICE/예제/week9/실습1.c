#include <stdio.h>

int main(void){

    int i = 0;      // while문 용 변수
    char str[4];    // 문자형 배열 크기는 4

    str[0] = 'a';   // 0에 저장
    str[1] = 'b';   // 1에 저장
    str[2] = 'c';   // 2에 저장
    str[3] = '\0';  // 3에 저장

    while( str[i] != '\0' ){    // 배열의 끝에는 '\0'이 있다.
        printf("%c",str[i++]);  // 문자를 하나씩 출력한다.
    }
    
    return 0;
}