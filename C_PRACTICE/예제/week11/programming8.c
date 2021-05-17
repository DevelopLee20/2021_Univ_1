#include <stdio.h> // 표준입출력 라이브러리
#define PI 3.14    // 파이값 선언

// point 구조체 선언
struct point
{
    int x, y;
};

// 변경 전 struct circle
// struct circle 
// {
//     struct point center; // 원의 중심
//     double radius;       // 원의 반지름
// };

// typedef 로 변경한 struct CIRCLE
typedef struct 
{
    struct point center; // 원의 중심
    double radius;       // 원의 반지름
} CIRCLE;

// 넓이 계산 함수
double area(CIRCLE c){ // 파이*반지름*반지름
    return (PI*c.radius*c.radius);
}

// 둘레 계산 함수
double perimeter(CIRCLE c){ // 2*파이*반지름
    return (2*PI*c.radius);
}

int main(void){

    CIRCLE c; // CIRCLE 구조체 선언

    // 중심점을 받아서 저장한다.
    printf("원의 중심점: ");
    scanf("%lf %lf", &c.center.x, &c.center.y);

    // 반지름을 받아서 저장한다.
    printf("원의 반지름: ");
    scanf("%lf", &c.radius);

    // 원의 면적과 반지름을 출력한다.
    printf("원의 면적=%lf, 원의 둘레=%lf\n", area(c), perimeter(c));

    return 0;
}