#include <stdio.h>
#include <stdarg.h>

int sum(int, ...);

int main(void){
    int answer  = sum(4,4,3,2,1);
    printf("sum: %d\n",answer);
    return 0;
}

int sum(int num, ...){
    int answer = 0;
    va_list argptr;

    va_start(argptr, num);
    for(; num>0; num--){
        printf("%d\n",*argptr);
        answer += va_arg(argptr, int);
        printf("%d\n",*argptr);
        answer += va_arg(argptr, int);
    }
    va_end(argptr);
    
    return answer;
}