#include <stdio.h> // 표준입출력 헤더파일

// 열겨형 days 변수 SUN부터 1을 가진다.
enum days { SUN , MON , TUE , WED , THU , FRI , SAT };

// 포인터 배열 선언
char *days_name[] = {
    "sunday" , "monday" , "tuesday" , "wednesday" , "thursday" , "friday" , "saturday"
};

int main(void){
    enum days d; // 열겨형 변수 d 사용

    d = WED; // WED 번째 정수가 저장된다.
    printf("%d 번째 요일은 %s 입니다.", d, days_name[d]);

    return 0;
}