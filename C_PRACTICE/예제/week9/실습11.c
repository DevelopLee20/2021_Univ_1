#include <string.h>
#include <stdio.h>

int main(void){

    char s[] = "language";
    char c = 'g';
    char *p;
    int loc;

    p = strchr(s,c);    // 'g'가 있는 s위치의 주소값을 반환
    loc = (int)(p-s);   // 주소값 계산

    if ( p != NULL ){
        printf("첫번째 %c가 %d에서 발견되었음\n",c,loc);
    }
    else{
        printf("%c가 발견되지 않았음\n",c);
    }

    return 0;
}