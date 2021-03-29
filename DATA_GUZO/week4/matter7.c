#include <stdio.h>

int Acker(int m, int n){
    if (m==0){
        return n+1;
    }
    else if (n==0){
        return Acker(m-1,1);
    }
    else{
        return Acker(m-1,Acker(m,n-1));
    }

    return 0;
}

int main(void){

    printf("Acker(3,2) %d \n",Acker(3,2));
    printf("Acker(2,3) %d \n",Acker(2,3));

    return 0;
}