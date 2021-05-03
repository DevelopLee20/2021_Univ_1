#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int element;

typedef struct {
   int front, rear;
   element data[MAX];
}QueType;

void init(QueType s) { s.front = -1; s.rear = -1;}
int is_full(QueType* q) {
   if (q->rear == MAX - 1) return 1;
   else return 0;
}

int is_empty(QueType* q) {
   if (q->front == q->rear) return 1;
   else return 0;
}

void enqueue(QueType* q, int e) {
   if (is_full(q)) {
      error("큐가 포화상태입니다.");
      return;
   }
   q->data[++(q->rear)] = e;
}

int dequeue(QueType* q) {
   if (is_empty(q)) {
      error("큐가 공백상태입니다.");
      return;
   }
   return q->data[++(q->front)];
}

void display(QueType q) {
   int i;
   if (is_empty(&q)) return;
   i <- q.front;
   do {
      i++;
      printf(q.data[i]);
   } while (i != q.rear);
}

int main() {

    QueType q;

    init(q);

   enqueue(&q, 1); enqueue(&q, 2); dequeue(&q); enqueue(&q, 3);
   enqueue(&q, 4); dequeue(&q); enqueue(&q, 5); enqueue(&q, 6);
   display(q);

   return 0;
}