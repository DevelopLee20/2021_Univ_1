#include <stdio.h>
#include <stdlib.h>

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

ListNode* consList(int array[], int size){

    ListNode *list = NULL;

    while(size){
        list = insert_last(list, array[--size]);
    }

    return list;
}

ListNode* merge(ListNode *head1, ListNode *head2){
    
    ListNode *list1 = head1;    // (1)
    ListNode *list2 = head2;    // (1)
    ListNode *merging = NULL;   // (1)

    while( list1 != NULL && list2 != NULL ){ // (2)
        if(list1->data > list2->data){ // (3)
            merging = insert_last(merging, list2->data);
            list2 = list2->link;
        }
        else{ // (3)
            merging = insert_last(merging, list1->data);
            list1 = list1->link;
        }
    }

    while( list1 != NULL ){ // (4)
        merging = insert_last(merging, list1->data);
        list1 = list1->link;
    }

    while( list2 != NULL ){ // (4)
        merging = insert_last(merging, list2->data);
        list2 = list2->link;
    }

    return merging; // (5)
}

int main(void){
    
    ListNode *list1, *list2, *list;
    int a[] = {7,5,3,1}, b[] = {5,4,2};

    // 배열을 매개변수로 전달받아서 리스트 생성
    list1 = consList(a, 4);
    list2 = consList(b, 3);

    // 리스트 합병
    list = merge(list1, list2);

    // 리스트 출력
    print_list(list1); print_list(list2); print_list(list);

    return 0;
}