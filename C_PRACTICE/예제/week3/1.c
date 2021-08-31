#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    for(int i=0; i<100; i++){
        int i = rand();
        printf("%d\n",i);
    }

    return 0;
}