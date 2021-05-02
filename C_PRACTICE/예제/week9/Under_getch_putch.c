#include <stdio.h>
#include <conio.h>

// ㅋㅋ 먼지 모르겠네
int main(void){

    int ch;
    
    // 그냥 입력되는게 q면 종료함
    // Enter 모든게 안먹음(개행문자 절대 안먹음)
    while( (ch = _getch() ) != 'q' ){
        _putch(ch);
    }
    
    return 0;
}