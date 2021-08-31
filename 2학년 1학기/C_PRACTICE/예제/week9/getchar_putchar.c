#include <stdio.h>

int main(void){

    int ch;

    // EOF는 EndOfFile인데 개행문자 ^z는 인식한다.
    while( (ch = getchar()) != EOF ){
        putchar(ch);
    }

    return 0;
}