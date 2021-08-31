// 과제 : isspace() 함수를 사용하여 변경하시오.

#include <stdio.h>  // 표준입출력 헤더파일
#include <ctype.h>  // isspace를 사용할 수 있는 헤더파일

int used_isspace( char *s ){

    int i = 0;              // 카운트용 변수
    int space_count = 1;    // 단어의 개수를 리턴할 변수

    // 컴파일러 상에서의 오류로 NULL에서 같은 의미인 '\0'으로 변경
    // warning: comparison between pointer and integer
    while( s[i] != '\0' ){          // '\0'일때까지 반복
        if ( isspace(s[i++]) ){     // isspace() 로 변경
            space_count++;          // 단어의 개수를 1 증가한다.
        }
    }

    return space_count; // 공백 + 1 = 단어의 개수로 계산한다.
}

int main(void){

    // 문장을 입력해서 함수에 매개변수로 전달 후 값을 리턴 받는다.
    printf("단어의 개수: %d\n", used_isspace("the c book..."));

    return 0;   // 프로그램의 정상 종료를 판단한다.
}