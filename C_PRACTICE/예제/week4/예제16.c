#include <stdio.h>
#define YEARS 3
#define PRODUCTS 5

int sum(int scores[YEARS][PRODUCTS]);

int main(void){
    int sales[YEARS][PRODUCTS] = {{1,2,3},{2,3,4},{4,5,6}};
    int total_sale;

    total_sale = sum(sales);
    printf("%d\n",total_sale);

    return 0;
}

int sum(int scores[YEARS][PRODUCTS])
{
    int total = 0;

    for(int y=0; y<YEARS; y++)
        for(int p=0; p<PRODUCTS; p++)
            total += scores[y][p];
    
    return total;
}