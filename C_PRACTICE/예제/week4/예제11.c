#include <stdio.h>
#define SIZE 10

int seq_search(const int list[], int key){
    int i;
    for(i=0; i<SIZE; i++){
        if(list[i] == key){
            return i;
        }
    }
    return -1;
}

int main(void){
    int key, ret;
    int list[SIZE] = {1,2,3,4,5,6,7,8,9};

    scanf("%d",&key);

    ret = seq_search(list,key);
    if( ret > 0)
        printf("탐색 성공 인덱스 = %d\n",ret);
    else
        printf("탐색 실패\n");
    return 0;
}