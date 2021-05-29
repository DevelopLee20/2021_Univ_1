#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

ListNode* get_node(int data){

    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;

    return node;
}

ListNode* insert_first(ListNode *list, int data){

    if(list == NULL){
        list = get_node(data);
        list->link = list;
        return list;
    }

    ListNode *node = get_node(data);

    node->link = list->link;
    list->link = node;

    return list;
}

ListNode* insert_last(ListNode *list, int data){

    if(list == NULL){
        list = get_node(data);
        list->link = list;
        return list;
    }

    ListNode *node = get_node(data);

    node->link = list->link;
    list->link = node;
    list = list->link;

    return list;
}

void print_list(ListNode *list){

    ListNode *end = list;
    end = end->link;

    printf("|");

    while(end != list){
        printf(" %d |",end->data);
        end = end->link;
    }
    printf(" %d |",end->data);

}

int main(void){

    ListNode *list = NULL;

    list = insert_first(list, 10);
    list = insert_first(list, 20);
    list = insert_first(list, 30);

    list = insert_last(list, 40);
    list = insert_last(list, 50);

    print_list(list);

    return 0;
}