#include <stdio.h>

int main(void){
    
    char name[100];
    char address[100];

    printf("이름을 입력하시오: ");
    scanf("%s", name);      // Enter 개행은 입력되지 않는다.

    printf("현재 거주하는 주소를 입력하시오: ");
    scanf("%s", address);   // Enter 개행은 입력되지 않는다.

    printf("이름: %s\n", name);
    printf("주소: %s\n", address);

    return 0;
}