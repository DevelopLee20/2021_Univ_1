#include <stdio.h>

struct point
{
    int x;
    int y;
};

int main(void){
    struct point p1 = {10,20};
    struct point p2 = {30,40};

    p2 = p1;

    // 올바르지 않은 비교
    // if ( p1 == p2 ){
    //     printf("같습니다.");
    // }
    
    // 올바른 비교
    if ((p1.x == p2.x) && (p1.y == p2.y)){
        printf("같습니다.");
    }

    return 0;
}