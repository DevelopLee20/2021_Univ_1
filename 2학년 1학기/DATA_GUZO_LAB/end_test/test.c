#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

ListNode* get_node(int data){

    // 노드 동적 생성
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data; // data 입력

    return node; // 생성된 노드 반환
}

ListNode* insert_first(ListNode *list, int data){

    if(list == NULL){ // 초기상태일때 노드를 생성하고 종료
        list = get_node(data);
        list->link = list;
        return list;
    }

    ListNode *node = get_node(data); // 노드 동적 생성

    node->link = list->link;
    list->link = node;

    return list;
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

void print_list(ListNode *head){

    ListNode *p = head;

    p = head->link;
    while(p != head){
        printf("%d ",p->data);
        p = p->link;
    }
    printf("%d ",head->data);
}

int main(void){

    ListNode *list = NULL;

    list = insert_first(list, 10);
    list = insert_first(list, 20);
    list = insert_first(list, 30);
    list = insert_last(list, 40);
    list = insert_last(list, 50);

    printf("정답: 30 20 10 40 50\n");
    printf("지현: ");
    print_list(list);

    return 0;
}