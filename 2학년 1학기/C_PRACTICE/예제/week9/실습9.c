#include <string.h>
#include <stdio.h>

int main(void){

    char string[80];

    strcpy(string, "Hello world from ");    // 복사함
    strcat(string, "strcpy ");              // 뒤에 연결함
    strcat(string, "and ");                 // 뒤에 연결함
    strcat(string, "strcat!");              // 뒤에 연결함

    printf("string = %s\n", string);

    return 0;
}