#include <stdio.h>

int main(void){
    int num;
    int div_two = 0;
    int none_div_two = 0;

    for (int i=0; i<10; i++){
        printf("%d번째 수: ",i+1);
        scanf("%d",&num);
        if (num%2==0)
            div_two += 1;
        else
            none_div_two += 1;
    }

    printf("짝수의 합: %d\n",div_two);
    printf("홀수의 합: %d",none_div_two);

}