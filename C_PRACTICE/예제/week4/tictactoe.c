#include <stdio.h>

int main(void){
    char board[3][3];
    
    int x,y,k,i;

    for(x=0; x<3; x++){
        for(int y=0; y<3; y++){
            board[x][y] = ' ';
        }
    }

    for(k=0; k<9; k++){
        printf("(x,y) 좌표: ");
        scanf("%d %d",&x,&y);
        board[x][y] = (k%2==0) ? 'X':'O';

        for(i=0; i<3; i++){
            printf("---|---|---|\n");
            printf("%c | %c | %c \n",board[i][0], board[i][1], board[i][2]);
        }
        printf("---|---|---|\n");
    }
    return 0;
}