#include <stdio.h> // 표준입출력 라이브러리

typedef struct point {
    int x; // 구조체 변수
    int y; // 구조체 변수
} POINT;

// 구조체 POINT를 반환값으로 가지는 함수
POINT translate(POINT p, POINT delta){
    POINT new_p;

    // x좌표의 합과 y좌표의 합을 저장해서 구조체를 반환한다.
    new_p.x = p.x + delta.x;
    new_p.y = p.y + delta.y;

    return new_p;
}

int main(void){
    POINT p = { 2 , 3 };       // 구조체 p 선언 및 초기화
    POINT delta = { 10 , 10 }; // 구조체 delta 선언 및 초기화
    POINT result;              // 구조체 result 선언

    result = translate(p, delta); // 구조체를 반환하는 함수에 넣는다.
    // 결과 출력
    printf("새로운 점의 좌표는 (%d , %d)입니다.\n", result.x, result.y);

    return 0;
}