#include <stdio.h> 

int get_sum(int array[], int size){
    int *p, *q;
    int b = 0;

    p = &array[0];
    q = &array[size-1];

    for (; p <= q;){
        b += *p++;
    }
    return b;
}
int main(void) {
    int a[3][6] = { {10,10,10,10,10,10},{10,10,10,10,10,10},{10,10,10,10,10,10} };
    int b = 0;
    for (int i = 0; i < 3; i++) {
        b += get_sum(a[i],6);
    }
    printf("%d", b);
    return 0;
}