#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct{
    int front, rear;
    int data[MAX_QUEUE_SIZE];
} QueueType;

int init(QueueType *q){
    q -> front = 0; // front를 0으로 초기화
    q -> rear = 0;  // rear를 0으로 초기화
}

int is_empty(QueueType *q){
    // rear와 front가 같으면 빈 원형 큐
    if (q -> front == q -> rear){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full( QueueType *q ){
    // rear를 1 더한 후 front와 같으면 꽉찬 원형 큐이다.
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
    // rear을 1 더해서 데이터를 저장함
    q -> rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q -> data[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "[dequeue] 에러: 큐가 공백상태입니다.\n");
        exit(1);
    }
    // front를 1 더해서 데이터를 출력함
    q -> front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q -> data[q->front];
}

element peek(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "[peek] 에러: 큐가 비어있습니다.\n");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void display(QueueType *q){

    int i = q->front+1; // 출력의 시작점을 front+1 로 정함

    printf("Queue front = %d, rear = %d\n", q->front, q->rear);

    printf("|");

    // rear 까지 출력 할 수 있도록 함
    if (!is_empty(q)){
        i = i % MAX_QUEUE_SIZE;
        while((i) != ((q->rear+1) % MAX_QUEUE_SIZE)){
            printf(" %d |", q->data[i++]);
            i = (i % MAX_QUEUE_SIZE);
        }
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct{
    int front, rear;
    int data[MAX_QUEUE_SIZE];
} QueueType;

int init(QueueType *q){
    q -> front = 0; // front를 0으로 초기화
    q -> rear = 0;  // rear를 0으로 초기화
}

int is_empty(QueueType *q){
    // rear와 front가 같으면 빈 원형 큐
    if (q -> front == q -> rear){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full( QueueType *q ){
    // rear를 1 더한 후 front와 같으면 꽉찬 원형 큐이다.
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
    // rear을 1 더해서 데이터를 저장함
    q -> rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q -> data[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "[dequeue] 에러: 큐가 공백상태입니다.\n");
        exit(1);
    }
    // front를 1 더해서 데이터를 출력함
    q -> front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q -> data[q->front];
}

element peek(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr, "[peek] 에러: 큐가 비어있습니다.\n");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void display(QueueType *q){

    int i = q->front+1; // 출력의 시작점을 front+1 로 정함

    printf("Queue front = %d, rear = %d\n", q->front, q->rear);

    printf("|");

    // rear 까지 출력 할 수 있도록 함
    if (!is_empty(q)){
        i = i % MAX_QUEUE_SIZE;
        while((i) != ((q->rear+1) % MAX_QUEUE_SIZE)){
            printf(" %d |", q->data[i++]);
            i = (i % MAX_QUEUE_SIZE);
        }
    }
    printf("\n");
}

int fibo_que(int n)
{
    QueueType q, result;
    int f;
    init(&q);
    init(&result);
    enqueue(&q, 0);
    enqueue(&q, 1);
    while (n > 1) {
        f = q.data[q.rear] + dequeue(&q);
        enqueue(&result, f);
    }
    display(&result);
}

int main(void) 
{
    int n;
    printf("n 입력: ");
    scanf("%d", &n);
    printf("결과: %d\n", fibo_que(n));
    return 0;
}