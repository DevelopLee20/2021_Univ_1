#include <stdio.h>
#include <stdlib.h>
#define Array_Size 4

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

ListNode* get_node(int item){

    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = item;
    node->link = NULL;

    return node;

}

ListNode* insert_first(ListNode *list, int val){
    
    ListNode *node = get_node(val);
    node->link = list;

    return node;

}

// 새로 만듬
ListNode* insert_last(ListNode *list, int val){
    
    ListNode *p = list;

    if(p == NULL){
        list = insert_first(p, val);
    }

    else{
        while(p->link != NULL){
            p = p->link;
        }
        ListNode *node = get_node(val);
        p->link = node;
    }

    return list;
}

void print_list(ListNode *list){

    printf("|");

    ListNode *p = list;

    while(p != NULL){ // NULL을 만날때까지 반복
        printf(" %d |", p->data);
        p = p->link;
    }
    
    printf("\n");
}

ListNode* delete_first(ListNode *list){
    
    ListNode *remove;

    if(list == NULL){
        fprintf(stderr, "[delete_first] Error: list is not have link");
    }
    else{
        remove = list;
        list = remove->link; // list = list->link
        free(remove);
        
        return list;
    }
}

// 배열과 배열의 크기를 매개변수로 받는다.
// 요소 값을 포함하는 노드 생성
// insert_first를 사용해서 삽입한다.
// 구성된 리스트 반환
ListNode* consList(int array[], int size){

    ListNode *list = NULL;

    while(size){
        list = insert_last(list, array[--size]);
    }

    return list;
}

int main(void){
    
    ListNode *head = NULL;

    int array[Array_Size] = {7,5,3,1};

    head = consList(array, Array_Size);

    print_list(head);

    return 0;
}