#include <stdio.h>

int main(void){

    char c;
    char s[80], t[80];

    printf("스페이스로 분리된 문자열을 입력하시오: ");
    scanf("%s%c%s", s, &c, t); // 문자열, 문자, 문자열 읽기

    printf("입력된 첫번째 문자열=[%s]\n", s);   // 첫번째 문자열
    printf("입력된 문자=[%c]\n", c);           // 공백
    printf("입력된 두번째 문자열=[%s]\n", t);   // 두번째 문자열

    return 0;
}