#include <stdio.h>

int main(void){
    int iii[3][3] = {{1,2,3},{2,3,4},{4,5,6}};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ",iii[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}