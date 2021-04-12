#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int** table = (int**)malloc(5*sizeof(int*));
    for(int i = 0 ; i < 5;i++){
        table[i] = (int*)malloc(sizeof(int)*i);
        for(int j = 0  ; j <= i; j++){
            table[i][j] = j+1;
        }
    }

    for(int i = 0 ; i < 5;i ++){
        for(int j = 0 ; j <= i; j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
}