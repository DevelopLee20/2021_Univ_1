#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 10

typedef int element;

typedef struct{
    element data[MAX_DEQUE_SIZE];
    int front, rear;
} DequeType;

void init_deque(DequeType *d){
    d->front = 0;
    d->rear = 0;
}

int is_empty(DequeType *d){
    return (d->front == d->rear);
}

int is_full(DequeType *d){
    return ((d->rear + 1) % MAX_DEQUE_SIZE == d->front);
}

void add_rear(DequeType *d, int item){
    if(is_full(d)){
        fprintf(stderr, "[enqueue] 에러: 큐가 포화상태입니다.\n");
        return;
    }
    // rear을 1 더해서 데이터를 저장함
    d -> rear = (d->rear + 1) % MAX_DEQUE_SIZE;
    d -> data[d->rear] = item;
}

element delete_front(DequeType *d){
    if(is_empty(d)){
        fprintf(stderr, "[dequeue] 에러: 큐가 공백상태입니다.\n");
        exit(1);
    }

    d -> front = (d->front + 1) % MAX_DEQUE_SIZE;
    return d -> data[d->front];
}

element get_front(DequeType *d){
    if(is_empty(d)){
        fprintf(stderr, "[peek] 에러: 큐가 비어있습니다.\n");
        exit(1);
    }
    return d->data[(d->front + 1) % MAX_DEQUE_SIZE];
}

element delete_rear(DequeType *d){
    if(is_empty(d)){
        fprintf(stderr, "[delete_rear] 에러: 큐가 공백상태입니다.");
    }
    int seed = d->rear;
    d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return d->data[seed];
}

void add_front(DequeType *d, element seed){
    if(is_full(d)){
        fprintf(stderr, "[add_front] 에러: 큐가 포화상태입니다.");
    }
    d->data[d->front] = seed;
    d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

element get_rear(DequeType *d){
    if(is_empty(d)){
        fprintf(stderr, "[get_rear] 에러: 큐가 고백상태입니다.");
    }
    return d->data[d->rear];
}

int is_palin(DequeType *d, char s[]){

    char a, b;
    int i = 0;
    
    while(s[i] != '\0'){
        add_rear(d, s[i++]);
    }

    while(1){

        printf("is_empty: %d\n",is_empty(d));
        if(!is_empty(d)){
            a = delete_front(d);
        }
        else{
            return 1;
        }
        
        printf("is_empty2: %d\n",is_empty(d));
        if(!is_empty(d)){
            b = delete_rear(d);
        }
        else{
            return 1;
        }

        printf("a == b: %d\n",a==b);
        if(a == b){
            delete_front(d);
            delete_rear(d);
        }
        else{
            return 0;
        }
    }
}

int main(void){

    DequeType d;

    init_deque(&d);

    char s[10] = "data";

    printf("check: %d\n", is_palin(&d, s));

    return 0;     
}