// 에러남

#include <stdio.h>

#define ASSERT(exp) { if (!(exp)) \{ printf("가정("#exp")이 소스 파일 %s %d 번째 줄에서 실패.\n",\ __FILE__, __LINE__), exit(1);}}

int main(void){

    int sum = 100;

    ASSERT(sum == 0);

    return 0;
}