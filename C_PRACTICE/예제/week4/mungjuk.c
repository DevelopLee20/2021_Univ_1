#include <stdio.h>

int paper[100][100];

void drawRectangle(int x, int y, int height, int width){
    int i, j;
    for(i=x; i<x + height; i++){
        for(j=y; j<y + width; j++){
            paper[i][j] = 1;
        }
    }
}

int computerArea(){
    int i, j, area = 0;
    for(i=0; i<100; i++){
        for(j=0; j<100; j++){
            area += paper[i][j];
        }
    }
    return area;
}

int main(){
    drawRectangle(3,5,10,5);
    drawRectangle(6,4,5,3);
    printf("%d\n",computerArea());

    return 0;
}