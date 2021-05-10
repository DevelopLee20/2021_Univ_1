#include <stdio.h>  // 표준입출력 라이브러리

struct point{       // point 구조체
    int x;          
    int y;
};

struct rect{        // struct를 변수로 가진 rect 구조체
    struct point p1;
    struct point p2;
};

int main(void){
    struct rect r;          // rect 구조체 r 선언
    int w, h, area, peri;   // 사용할 변수 선언

    printf("왼쪽 하단의 좌표를 입력하시오: ");
    scanf("%d %d", &r.p1.x, &r.p1.y);       // 왼쪽 좌표 입력

    printf("오른쪽 상단의 좌표를 입력하시오: ");
    scanf("%d %d", &r.p2.x, &r.p2.y);       // 오른쪽 좌표 입력

    w = r.p2.x - r.p1.x;    // x좌표에 따라서 너비를 구함
    h = r.p2.y - r.p1.y;    // y좌표에 따라서 높이를 구함

    area = w * h;           // 너비와 높이를 곱해서 넓이를 구함  
    peri = 2 * w + 2 * h;   // 너비와 높이를 *2 해서 둘레를 구함
    printf("면적은 %d이고 둘레는 %d입니다.\n", area, peri);

    return 0;
}