#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int list[100];

// 랜덤 배열 생성
void randompick(){
    int count = 0;
    srand((unsigned)time(NULL));
    while(count!=100){
        list[count] = (rand()%1000) + 1;
        
        int check = 1;
        for(int i=0; i<count; i++){
            if (list[i] == list[count]){
                check = 0;
                break;
            }
        }

        if(check){
            count++;
        }
    }
}

// 선택정렬 알고리즘
void selectionSort(int *list, int n){
    int i, j;

    for(i=0; i<n-1; i++){
        int min = i;

        for(j=i+1; j<n; j++){
            if(list[j] < list[min]){
                min = j;
            }
        }

        int swap = list[min];
        list[min] = list[i];
        list[i] = swap;
    }
}

// 이진탐색 알고리즘
int binary_search(int *list, int n, int key){
    int low, high, middle;
    low = 0;
    high = n-1;

    while(low<=high){
        middle = (low +high)/2;
        if(key == list[middle])
            return middle;
        else if(key > list[middle])
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

// 순차탐색 알고리즘
int seq_search(int *list, int key, int low, int high){
    for(int i=0; i<=high; i++)
        if(list[i] == key)
            return i;
    return -1;
}

void timer(){
    clock_t start, end;

    start = clock();
    // 함수 입력
    end = clock();

    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%.4lf",duration);
}

int main(void){
    randompick();
    int array1[100], array2[100], array3[100];

    memcpy(array1,list,sizeof(list));
    memcpy(array2,list,sizeof(list));
    memcpy(array3,list,sizeof(list));

    seq_search(*array1,key,low,high);
    binary_search(*array2, n, key);
    selectionSort(*array3, n);

    return 0;
}