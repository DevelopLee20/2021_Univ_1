#include <stdio.h>

int main(void){

    char str1[6] = "Seoul";                     // 문자열을 초기화1
    char str2[3] = {'i','s','\0'};              // 문자열을 초기화2
    char str3[] = "the capital city of Korea."; // 문자열을 초기화3

    printf("%s %s %s\n", str1, str2, str3);     // 문자열 출력
    
    return 0;
}