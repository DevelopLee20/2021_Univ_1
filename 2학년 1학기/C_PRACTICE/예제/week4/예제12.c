#include <stdio.h>
#define SIZE 16

list[];

int binary_search(int list[], int n, int key){
    int low, high, middle;
    low = 0;
    high = n-1;
    while(low <= high){
        printf("[%d %d]\n",low, high);
        middle = (low + high)/2;
        if (key == list[middle]){
            return middle;
        }
        else if (key > list[middle])
            low = middle + 1;
        else
            high = middle -1;
    }
    return -1;
}