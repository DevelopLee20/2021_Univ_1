#include <string.h>
#include <stdio.h>

int main(void){

    char s[] = "A joy that's shared is a joy made double";
    char sub[] = "joy";
    char *p;
    int loc;

    p = strstr(s, sub);     // 문자열에서 문자열을 찾은 후 주소값을 반환한다.
    loc = (int)(p-s);
    
    if ( p != NULL ){
        printf("첫 번째 %s가 %d에서 발견되었음\n", sub, loc);
    }
    else{
        printf("%s가 발견되지 않았음\n", sub);
    }
}