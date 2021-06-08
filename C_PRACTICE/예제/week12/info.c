#include "info.h"

void flag(){
    printf("---플래그---\n");
    printf("%d\n",123);
    printf("%010d\n",123);
    printf("% d\n",123);
    printf("%+d\n",123);
    printf("%d\n",-123);
    printf("%#x\n",0x10); // 앞에 '0x'를 출력한다.
    printf("\n");
}

void field_gap(){
    printf("---필드폭---\n");
    printf("%10d\n",123);
    printf("%-10d\n",123);
    printf("%10d\n",-123);
    printf("%-10d\n",-123);
    printf("%10s\n","abc");
    printf("%-10s\n","abc");
    printf("\n");
}

void precision(){
    printf("---정밀도---\n");
    printf("%f\n",1.23456789);
    printf("%10.3f\n",1.23456789);
    printf("%-10.3f\n",1.23456789);
    printf("%.3f\n",1.23456789);
    printf("\n");
}

void float_print(){
    printf("---실수의 출력---\n");
    printf("%f\n",1.23456789);
    printf("%e\n",1.23456789);
    printf("%10.3e\n",1.23456789);
    printf("%-10.3e\n",1.23456789);
    printf("\n");
}

int main(void){
    flag();
    field_gap();
    precision();
    float_print();
}