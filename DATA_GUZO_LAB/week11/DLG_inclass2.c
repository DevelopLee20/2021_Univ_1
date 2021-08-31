#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *link;
} ListNode;

ListNode* get_node(int item){

    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = item;
    p->link = NULL;

    return p;
}

insert_first