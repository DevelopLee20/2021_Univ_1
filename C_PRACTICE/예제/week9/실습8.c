#include <stdio.h>
#include <ctype.h>

int main(void){

    int c;

    while(( c = getchar() ) != EOF ){
        
        if( islower(c) ){   // 소문자면 1 아니면 0
            c = toupper(c); // to라서 변경하는 것임
        }

        putchar(c);
    }

    return 0;
}