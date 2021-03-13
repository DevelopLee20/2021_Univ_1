#include <stdio.h>

int calc_balance(double money){
    for(int i=0; i<10; i++){
        money = money*(1.06);
    }

    return money;
}

int main(void){
    double money;
    printf("입금된 금액: ");
    scanf("%lf",&money);

    int after = calc_balance(money);

    printf("10년 후 잔고: %d원",after);

    return 0;
}