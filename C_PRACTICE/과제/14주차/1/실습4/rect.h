// #pragma once 컴파일러상의 작동 오류로 아래 코드로 대체
#include "rect.c"

struct rect
{
    int x,y,w,h;
};

typedef struct rect RECT;

void draw_rect(const RECT *);
double calc_area(const RECT *);
void move_rect(RECT *, int, int);