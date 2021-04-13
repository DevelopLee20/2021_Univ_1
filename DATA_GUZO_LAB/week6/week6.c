#include <stdio.h>
#include <stdlib.h>

struct node{
    int val; // 값
    struct node *next; // 다음 노드
};

int main(void){

    typedef struct node nodeType; // node 구조체를 nodeType으로 재정의
    nodeType *first, *p, *q, *r; // nodeType의 포인터 4개를 생성

    // p, q, r 동적 생성
    p = (struct node*)malloc(sizeof(struct node));
    q = (struct node*)malloc(sizeof(struct node));
    r = (struct node*)malloc(sizeof(struct node));

    // next 값을 NULL로 초기화
    p -> next = NULL;
    q -> next = NULL;
    r -> next = NULL;
    
    // first 동적 생성
    first = (struct node*)malloc(sizeof(struct node));

    // 노드 순서대로 설정하고, 값을 대입한다.
    first->next = p;
    p -> val = 10;

    p->next = q;
    q -> val = 20;

    q->next = r;
    r -> val = 30;

    // 노드의 순서를 저장할 포인터 선언
    struct node *carry = first->next;

    // 3개의 노드를 순서대로 출력한다.
    for(int i=0; i<3; i++){
        printf("%d\n",carry->val);
        carry = carry -> next;
    }

    return 0;
}