#include <stdio.h>  // 표준입출력 라이브러리

struct student      // 구조체 student 생성
{
    int number;
    char name[20];
    double grade;
};


int main(void){
    struct student s = { 20070001, "홍길동", 4.3 }; // 구조체 student s 선언
    struct student *p;  // 구조체의 포인터 p 선언

    p = &s;     // p는 s의 주소를 가지고 있음

    printf("%d %s %f\n", s.number, s.name, s.grade);
    printf("%d %s %f\n",(*p).number, (*p).name, (*p).grade);
    printf("%d %s %f\n",p->number, p->name, p->grade);

    return 0;
}