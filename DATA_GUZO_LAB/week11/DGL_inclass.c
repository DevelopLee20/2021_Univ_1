#include <stdio.h>  // 표준입출력 헤더파일
#include <stdlib.h> // 표준라이브러리 헤더파일
#define MAX_LIST_SIZE 10 // 리스트의 크기를 제시

typedef struct{
    int array[MAX_LIST_SIZE]; // 리스트 내용을 저장
    int size;                 // 리스트 크기를 저장
} ArrayListType;              // 이름을 ArrayListType으로 지정

void init(ArrayListType *l){
    l->size = 0; // 초기화시에 size는 0이 됨
}

int is_empty(ArrayListType *l){
    return l->size == 0;
}

int is_full(ArrayListType *l){
    return l->size == MAX_LIST_SIZE;
}

void insert_last(ArrayListType *l, int item){
    if ( l->size == MAX_LIST_SIZE ){
        fprintf(stderr, "[insert_last] Overflow");
        exit(1);
    }
    l->array[l->size++] = item;
}

void insert(ArrayListType *l, int pos, int item){
    if (is_full(l) || (pos < 0) || (pos >= l->size)){
        fprintf(stderr, "[insert] Position Error");
        exit(1);
    }
    for(int i = (l->size - 1); i >= pos; i--){
        l->array[i+1] = l->array[i];
    }
    l->array[pos] = item;
    l->size++;
}

void delete(ArrayListType *l, int pos){
    if ( pos < 0 || pos >= l->size ){
        fprintf(stderr, "[delete] Position Error");
        exit(1);
    }

    for(int i = pos; i < (l->size-1); i++){
        l->array[i] = l->array[i+1];
    }
    l->size--;
}

void print_list(ArrayListType l){
    printf("size: %d\n", l.size);
    printf("array: |");
    for(int i=0; i < l.size; i++){
        printf(" %d |",l.array[i]);
    }
    printf("\n");
}

int main(void){

    ArrayListType list;

    init(&list);

    insert_last(&list, 10);
    insert_last(&list, 20);
    insert_last(&list, 30);
    delete(&list, 0);
    insert(&list, 1, 40);
    insert(&list, 0, 50);
    delete(&list, 1);

    print_list(list);

    return 0;
}