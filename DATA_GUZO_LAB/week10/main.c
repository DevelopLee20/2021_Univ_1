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

void fibo_que(int n){
    int f0 = 0; // 시작하는 수
    int f1 = 1; // 두번째 수
    int i = 0;  // 인덱스 확인

    QueueType q;    // 스택 생성

    init(&q);       // 스택을 초기화

    enqueue(&q, f0);// 스택에 추가
    enqueue(&q, f1);// 스택에 추가

    // 만약 1이거나 2이면
    // dequeue 해서 순서대로 출력되도록 한다
    if (n == 1){
        printf("fibo_que = %d\n", dequeue(&q));
    }

    else if (n == 2){
        dequeue(&q);
        printf("fibo_que = %d\n", dequeue(&q));
    }

    else{   // 2 이상이면 2개의 수를 합해서 스택이 넣는 것을 반복한다.
        while( i++ != n-2 ){
            int nf = dequeue(&q) + peek(&q);
            enqueue(&q, nf);
        }
        printf("fibo_que = %d\n", dequeue(&q)+dequeue(&q));
    }
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

    int num;
    printf("n을 입력하세요: ");
    scanf("%d",&num);

    fibo_que(num);

    return 0;
}