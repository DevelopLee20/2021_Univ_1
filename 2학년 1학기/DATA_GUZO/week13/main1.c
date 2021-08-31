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

    if(list == NULL){ // list가 초기상태일때 노드를 추가해줌
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
        printf(" %2d |",end->data);
        end = end->link;
    }
    printf(" (Head) %d |\n",end->data); // head의 data 값을 출력한다.
}

ListNode* sorted_insert(ListNode *list, int a){

    // (1)
    // 빈 리스트일 경우 단순 노드 추가
    if(list == NULL){ 
        list = get_node(a);
        list->link = list;

        return list;
    }

    // (2)
    // 리스트에 노드가 하나 밖에 없을 때
    // 앞이나 뒤 중 선택해서 추가
    else if(list->link == list){
        if( list->data < a ){
            list = insert_last(list, a);
            return list;
        }
        list = insert_last(list, a);
        return list->link; // 앞 일 경우 head를 조정
    }
    // (3)
    ListNode *end = list; // list 포인터를 복사

    // (4)
    // 노드의 링크의 data 값을 하나씩 비교해서 값을 추가
    do{
        if(end->link->data >= a){
            end = insert_last(end, a);
            return list;
        }
        end = end->link;
    } while(end != list); // (5)

    list = insert_last(list, a);

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