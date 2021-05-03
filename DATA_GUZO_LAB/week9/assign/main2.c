#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5            // 큐의 최대 크기를 지정한다.

typedef int element;                // int 데이터형을 element로 설정한다.

typedef struct{
    element data[MAX_QUEUE_SIZE];   // int 형 큐를 크기 5로 생성한다.
    int front, rear;                // front와 rear의 인덱스를 저장한다.
} QueueType;                        // 이름은 QueueType으로 설정한다.

void init( QueueType *q ){  // QueueType q를 초기화한다.
    q -> front = -1;        // front를 초기값으로 초기화한다.
    q -> rear = -1;         // rear를 초기값으로 초기화한다.
}

int is_full( QueueType *q ){    // 큐가 꽉 차있는지 확인한다.
    if ( q -> rear == MAX_QUEUE_SIZE - 1 ){
        return 1;
    }
    else{
        return 0;
    }
}

int is_empty( QueueType *q ){   // 큐가 비어있는지 확인한다.
    if ( q -> front == q -> rear ){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue( QueueType *q, int item ){ // 큐에 item을 하나 추기한다.
    if ( is_full(q)){
        printf("큐가 포화상태입니다.");
        exit(1);
    }
    q -> data[++(q->rear)] = item;
}

element dequeue( QueueType *q ){    // 큐에 front+1 인덱스 값을 제거한다.
    if ( is_empty(q)){
        printf("큐가 공백상태입니다.");
        exit(1);
    }
    return q -> data[++(q->front)];
}

void display( QueueType q ){            // 큐의 내용을 출력한다.

    int num = q.front;                  // front를 시작점으로 한다.

    while(num != q.rear){               // rear까지 출력한다.           
        printf("[%d] ",q.data[++num]);  // printf로 출력한다.
    }
}

int main(void){

    QueueType q;    // Queue 생성

    init(&q);       // 초기상태로 초기화

    enqueue(&q, 1); // 1 추가
    enqueue(&q, 2); // 2 추가
    dequeue(&q);    // Queue 빼기
    enqueue(&q, 3); // 3 추가
    enqueue(&q, 4); // 4 추가
    dequeue(&q);    // Queue 빼기
    enqueue(&q, 5); // 5 추가
    enqueue(&q, 6); // 6 추가

    display(q);     // 큐의 상태를 출력한다.

    return 0;
}