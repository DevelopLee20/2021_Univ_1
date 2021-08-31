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
    
    ListNode *p = list; // (1)

    if(p == NULL){ // (2)
        list = insert_first(p, val);
    }

    else{ // (3)
        while(p->link != NULL){
            p = p->link;
        }
        ListNode *node = get_node(val); // (4)
        p->link = node;
    }

    return list; // (5)
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

    ListNode *list = NULL; // (1)

    while(size){ // (2)
        list = insert_last(list, array[--size]);
    }

    return list; // (3)
}

int main(void){
    
    ListNode *head = NULL;

    int array[Array_Size] = {7,5,3,1};

    head = consList(array, Array_Size);

    print_list(head);

    return 0;
}