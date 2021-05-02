#include <stdio.h>

int main(void){

    // 애초에 포인터로 저장했기 때문에 요소를 수정불가능하다.
    char *p = "HelloWorld";
    printf("$s\n", p);

    p = "Welcome to C World!";
    printf("%s\n", p);

    p = "Goodbye";
    printf("%s\n", p);
    
    // p[0] = 'a'; 오류가 발생한다.
}