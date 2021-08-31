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

int main(void){

    ListNode *list = NULL; // init()

    list = insert_first(list, 10);
    list = insert_first(list, 20);
    list = insert_first(list, 30);

    printf("1) ");
    print_list(list);

    list = delete_first(list);
    list = insert_first(list, 40);
    list = insert_first(list, 50);
    list = delete_first(list);

    printf("2) ");
    print_list(list);

    return 0;
}