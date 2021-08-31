#include <stdio.h>

union exunion{
    int no;
    char ch[4];
};

void main(void){
    union exunion ex;

    ex.no = 0x0A0B0C0D;
    printf("no=%08x\n", ex.no);
    printf("ch:");

    for(int i=0; i<4; i++){
        printf("[%d]=%02x ", i, ex.ch[i]);
    }
}