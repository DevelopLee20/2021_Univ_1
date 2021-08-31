#include <stdio.h>
#define ROWS 3
#define COLS 5

int main(void){
    int a[ROWS][COLS] = {{10,20,30,40,50},
    {20,30,40,50,60},
    {30,40,50,60,70}};

    for(int i=0; i<ROWS i++){
        double final_scores = a[i][0] * 0.3 + a[i][1] * 0.4 + a[i][2] * 0.2 + a[i][3] * 0.1 - a[i][4];
        printf("%10.2f\n",i+1,final_scores);
    }
    return 0;
}