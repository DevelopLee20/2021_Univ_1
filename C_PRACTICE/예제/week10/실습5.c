#include <stdio.h>

struct student
{
    int number;
    char name[20];
    double grade;
};


int main(void){
    struct student s = { 20070001, "홍길동", 4.3 };
    struct student *p;

    p = &s;

    printf("%d %s %f\n", s.number, s.name, s.grade);
    printf("%d %s %f\n",(*p).number, (*p).name, (*p).grade);
    printf("%d %s %f\n",p->number, p->name, p->grade);

    return 0;
}