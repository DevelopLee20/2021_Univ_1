#include <stdio.h>  // 표준입출력 라이브러리
#include <stdlib.h> // 표준 라이브러리
#define MAX_QUEUE_SIZE 10 // 큐의 최대 사이즈

typedef int element; // 큐의 데이터 타입 

// Queue로 정의되어 있다.
typedef struct{
    int front, rear;
    int data[MAX_QUEUE_SIZE];
} QueueType;

int init(QueueType *q){
    q -> front = 0; // front를 0으로 초기화
    q -> rear = 0;  // rear를 0으로 초기화
}

// Queue의 is_empty와 같음
int is_empty(QueueType *q){
    // rear와 front가 같으면 빈 원형 큐
    if (q -> front == q -> rear){
        return 1;
    }
    else{
        return 0;
    }
}

// Queue의 is_full과 같음
int is_full( QueueType *q ){
    // rear를 1 더한 후 front와 같으면 꽉찬 원형 큐이다.
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

// Queue의 push와 같음
void push(QueueType *q1, int seed){
    if(is_full(q1)){
        fprintf(stderr, "[push] 에러: 큐가 포화상태입니다.");
        exit(1);
    }
    q1 -> rear = (q1->rear + 1) % MAX_QUEUE_SIZE;
    q1 -> data[q1->rear] = seed;
}

int pop(QueueType *q1, QueueType *q2){
    if(is_empty(q1)){
        fprintf(stderr, "[pop] 에러: 큐가 공백상태입니다.");
    }

    while(1){

        // 기본 pop 이지만 pop의 값을 seed로 둔다.
        q1 -> front = (q1->front + 1) % MAX_QUEUE_SIZE;
        int seed = q1 -> data[q1->front];

        if(is_empty(q1)){ // 마지막 값을 최종 seed 즉 스택의 top을 정해준다

            while(!is_empty(q2)){ // q2가 비어있지 않으면
                // q2에서 top을 제외한 값을 옮겨준다.
                q2 -> front = (q2->front + 1) % MAX_QUEUE_SIZE;
                push(q1, q2 -> data[q2->front]);
            }

            return seed; // 스택의 top을 반환한다.
        }

        else{ // 정해지기 전까지 seed를 제외한 나머지는 q2에 저장해 둔다.
            push(q2, seed);
        }
    }
}

int main(void){

    QueueType q1, q2; // Queue 2개를 선언

    init(&q1); // Queue 초기화
    init(&q2); // Queue 초기화

    // 스택에 저장한 숫자들
    int a[] = {1,2,3,4,5};

    // 스택에 차례로 저장
    for(int i=0; i<5; i++){
        push(&q1, a[i]);
    }

    // 스택을 출력해준다.
    printf("스택 출력: |");
    while(!is_empty(&q1)){
        printf(" %d |", pop(&q1, &q2));
    }
}