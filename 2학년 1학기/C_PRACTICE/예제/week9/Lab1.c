// 과제 : isspace() 함수를 사용하여 변경하시오.

#include <stdio.h>
#include <ctype.h>

int count_word(char *s);
int used_isspace( char *s );

int main(void){

    int wc = count_word("the c book...");
    int wc1 = used_isspace("the c book...");

    printf("단어의 개수: %d\n", wc);
    printf("단어의 개수: %d\n", wc1);

    return 0;
}

int used_isspace( char *s ){

    int i = 0;
    int space_count = 1;

    while( s[i] != '\0' ){
        if ( isspace(s[i++]) ){
            space_count++;
        }
    }

    return space_count;
}

int count_word( char *s ){

    int wc = 0, waiting = 1;

    // 컴파일러 상에서의 오류로 NULL에서 같은 의미인 '\0'으로 변경
    // warning: comparison between pointer and integer
    // for(int i = 0; s[i] != NULL; ++i){
    //                     ^~
    for(int i = 0; s[i] != '\0'; ++i){ 

        if ( isalpha(s[i] )){

            if ( waiting ){
                wc++;
                waiting = 0;
            }
        }
        else{
            waiting = 1;
        }
    }

    return wc;
}