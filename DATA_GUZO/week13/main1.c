#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

ListNode* get_node(int data){
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;

    return node;
}

ListNode* insert_last(ListNode *list, int data){

    if(list == NULL){ // list가 초기상태일때 그냥 노드를 추가해줌
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

    ListNode *end = list; // head 까지
    end = end->link; // head->link 부터

    printf("|");

    while(end != list){ // head까지 도착하면
        printf(" %d |",end->data);
        end = end->link;
    }
    printf(" (Head) %d |\n",end->data); // head의 data 값을 출력한다.
}

ListNode* insert_between(ListNode *list, int data){

}

ListNode* sorted_insert(ListNode *list, int a){

    if(list == NULL){
        list = get_node(list, a);

        return list
    }

    ListNode *point = list->link;

    while(point != list){
        if( a > point->data ){

        }
    }

    return list;
}

int main(void){

    ListNode* list = NULL;
    int a[10] = {12,56,2,11,33,60,1,3,25,55};

    for(int i=0; i<SIZE; i++){
        list = sorted_insert(list, a[i]);
    }

    print_list(list);

    return 0;
}