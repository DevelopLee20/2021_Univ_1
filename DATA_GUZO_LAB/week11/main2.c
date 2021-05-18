#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

ListNode* get_node(int item){

    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = item;

    return node;

}

ListNode* insert_first(ListNode *list, int val){
    
    ListNode *node = get_node(val);
    node->link = list;
    list = node;

    return list;

}

void print_list(ListNode *list){  // 애매함

    printf("|");

    ListNode *p = list;

    while(p != NULL){
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
        list = remove->link;
        free(remove);
        
        return list;
    }
}

int main(void){

    ListNode *list = NULL;

    list = insert_first(list, 10);
    list = insert_first(list, 20);
    list = insert_first(list, 30);

    print_list(list);

    list = delete_first(list);
    list = insert_first(list, 40);
    list = insert_first(list, 50);
    list = delete_first(list);

    print_list(list);

    return 0;
}