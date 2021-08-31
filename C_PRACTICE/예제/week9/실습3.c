#include <stdio.h>

int main(void){

    // 변수 초기화
    char src[] = "The worst things to eat before you sleep";
    char dst[100];
    int i = 0;
    
    printf("원본 문자열=%s\n", src);    // 원본 출력

    for(i=0; src[i] != '\0'; i++){      // 문자열의 끝을 보았을때 종료
        dst[i] = src[i];                // 그 내용을 모두 복사
    }

    dst[i] = '\0';  // NULL과 같다. 끝에 \0 을 저장해줌 (배열의 끝을 판단하기 위해서)

    printf("복사된 문자열=%s\n", dst);   // 출력

    return 0;
}