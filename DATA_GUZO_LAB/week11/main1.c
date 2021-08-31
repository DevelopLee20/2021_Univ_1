#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 10

typedef struct{
    int array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void init(ArrayListType *l){
    l->size = 0;
}

int is_empty(ArrayListType l){
    return ( l.size == 0 );
}

int is_full(ArrayListType l){
    return ( l.size == MAX_LIST_SIZE );
}

void insert_last(ArrayListType *l, int item){
    if(is_full(*l)){
        fprintf(stderr, "[insert_last] Error: List is full\n");
        exit(1);
    }
    l->array[l->size++] = item;
}

void insert(ArrayListType *l, int pos, int item){
    if(is_full(*l)){ // is_full 확인
        fprintf(stderr, "[insert] Error: List is full\n");
        exit(1);
    }
    else if(pos < 0 || pos >= l->size){ // pos 값 검사
        fprintf(stderr, "[insert] Error : Pos is wrong\n");
    }
    else{ // 둘 다 아니라면 insert 시작
        l->size++;
        for(int i=l->size; i>=pos; i--){
            l->array[i] = l->array[i-1];
        }
        l->array[pos] = item;
    }
}

void delete(ArrayListType *l, int pos){
    if(is_empty(*l)){ // is_empty 확인
        fprintf(stderr, "[delete] Error : List is empty\n");
        exit(1);
    }
    else if(pos < 0 || pos >= l->size){ // pos 값 검사
        fprintf(stderr, "[insert] Error : Pos is wrong\n");
    }
    else{ // 둘 다 아니라면 delete 시작
        for(int i=pos; i<l->size; i++){
            l->array[i] = l->array[i+1];
        }
        l->size--;
    }
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