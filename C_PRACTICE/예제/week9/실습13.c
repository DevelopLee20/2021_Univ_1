#include <string.h>
#include <stdio.h>

int main(void){

    char s[] = "Man is immortal, because he has a soul";
    char seps[] = ",\t\n";      // 개행 문자를 모두 저장
    char *token;

    token = strtok(s, seps);    // 개행 문자에 따라서 분리(포인터 저장)

    while( token != NULL ){
        printf("토큰: %s\n", token);
        token = strtok(NULL, seps);
    }

    return 0;
}