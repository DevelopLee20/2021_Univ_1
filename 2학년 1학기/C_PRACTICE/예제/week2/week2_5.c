#include <stdio.h>
#define TAX_RATE 0.2

int main(void){
    const int MONTHS = 12;
    int m_salary, y_salary;

    scanf("%d",&m_salary);

    y_salary = MONTHS * m_salary;

    printf("%d",y_salary);
    printf("%f",m_salary);

    return 0;
}