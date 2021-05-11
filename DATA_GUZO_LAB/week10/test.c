#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct{
    int front, rear;
    int data[MAX_QUEUE_SIZE];
} QueueType;

int init(QueueType *q){
    q -> front = 0;
    q -> rear = 0;
}

int is_empty(QueueType *q){
    if (q -> front == q -> rear){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full( QueueType *q ){
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(QueueType *q, int item){
    if(is_full(q)){
        fprintf(stderr, "[enqueue] 에러: 큐가 포화상태입니다.\n");
        return;
    }
    q -> rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q -> data[q->rear] = item;
    printf("[enqueue] rear: %d front: %d rear in data: %d\n", q->rear, q->front, q->data[q->rear]);
    
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "[dequeue] 에러: 큐가 공백상태입니다.\n");
        exit(1);
    }
    q -> front = (q->front + 1) % MAX_QUEUE_SIZE;
    printf("[dequeue] rear: %d front: %d rear in data: %d\n", q->rear, q->front, q->data[q->rear]);
    return q -> data[q->front];
}

element peek(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "[peek] 에러: 큐가 비어있습니다.\n");
    }
    printf("[peek] rear: %d front: %d rear in data: %d\n", q->rear, q->front, q->data[q->rear]);
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void display(QueueType *q){

    int i = q->front+1;

    printf("[display] rear: %d front: %d rear in data: %d\n", q->rear, q->front, q->data[q->rear]);
    printf("Queue front = %d, rear = %d\n", q->front, q->rear);

    printf("|");

    if (!is_empty(q)){
        i = i % MAX_QUEUE_SIZE;
        while((i) != ((q->rear+1) % MAX_QUEUE_SIZE)){
            printf(" %d |", q->data[i++]);
            i = (i % MAX_QUEUE_SIZE);
        }
    }
    printf("\n");
}

int main(void){

    QueueType q;

    init(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    dequeue(&q);
    enqueue(&q, 3);
    enqueue(&q, 4);
    dequeue(&q);
    enqueue(&q, 5);
    enqueue(&q, 6);

    display(&q);

    return 0;
}