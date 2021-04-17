// 헤더파일 임포트
#include <stdio.h>
#define ROWS 3
#define COLS 6

// get_sum 함수
int get_sum(int array[], int size){ // 1차원배열과 배열 사이즈를 받는다.

    int sum = 0; // 합을 저장할 변수
    int *p, *endp; // 시작 포인터와 끝 포인터

    p = &array[0]; // p 변수에는 array 행의 시작점 주소가 저장된다.
    endp = &array[size-1]; // endp 변수에는 array 행의 끝점 주소가 저장된다.

    while( p <= endp ){ // p값이 endp까지만 출력하도록 한다.
        // ++연산자는 자동으로 데이터형만큼 이동한다.
        sum += *p++; // sum 변수에 주소값을 하나씩 더해서 다음 값을 차례로 저장한다.
    }

    return sum; // sum 값을 리턴한다.
}

int main(void){

    // array 배열을 선언한다. [3][6] 크기로 생성된다.
    int array[ROWS][COLS] = {10,20,30,40,50,60,10,20,30,40,50,60,10,20,30,40,50,60};
    int sum = 0; // 합을 저장할 변수이다.

    // for문으로 반복해서 ROWS 만큼 반복한다.
    for(int i=0; i<ROWS; i++){
        sum += get_sum(array[i], COLS);
    }

    // 결과값을 출력한다.
    printf("정수의 합 = %d",sum);

    return 0;
}