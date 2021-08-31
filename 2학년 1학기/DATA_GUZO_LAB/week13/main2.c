#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode{
    int data;
    struct DListNode *llink;
    struct DListNode *rlink;
} DListNode;

void init(DListNode *head){
    head->llink = head;
    head->rlink = head;
}

DListNode* get_node(int data){

    DListNode *node = (DListNode *)malloc(sizeof(DListNode));
    node->data = data;

    return node;
}

void dinsert(DListNode *head, int data){

    DListNode *node = get_node(data);
    
    node->rlink = head->rlink;
    head->rlink->llink = node;
    head->rlink = node;
    node->llink = head;

}

void print_dlist(DListNode *head){

    DListNode *end = head; // head 노드

    end = end->rlink; // head의 rlink 부터

    printf("|");
    while( end != head ){ // head 노드가 나올때까지
        printf(" %d |", end->data);
        end = end->rlink;
    }
    
    printf("\n");
}

void dinsert_last(DListNode *head, int data){

    DListNode *node = get_node(data);

    head->llink->rlink = node;
    node->llink = head->llink;
    node->rlink = head;
    head->llink = node;
}

int main(void){

    DListNode *head = (DListNode *)malloc(sizeof(DListNode));

    init(head);

    for(int i=1; i<5; i++){
        dinsert(head, i);
    }

    print_dlist(head);

    dinsert_last(head, 5);
    print_dlist(head);

    return 0;
}