#include <stdio.h>

int main(void){
    
    int a, b;

    printf("6개의 숫자로 이루어진 정수를 입력하시오: ");
    scanf("%3d%3d", &a, &b); // 각각 3개씩 나누어서 a, b에 저장됨

    printf("입력된 정수는 %d, %d\n", a, b);

    return 0;
}