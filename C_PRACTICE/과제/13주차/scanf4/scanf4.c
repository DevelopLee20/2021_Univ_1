#include <stdio.h>

int main(void){
    char s[80];

    printf("문자열을 입력하시오: ");
    scanf("%[abc]", s); // abc로만 이루어진 문자열을 읽는다.

    printf("입력된 문자열=%s\n", s);

    return 0;
}