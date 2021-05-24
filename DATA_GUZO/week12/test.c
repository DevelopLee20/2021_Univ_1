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
    
    ListNode *list1 = head1;
    ListNode *list2 = head2;
    ListNode *merging = NULL;

    if(list1->data > list2->data){
        merging = insert_last(list1);
        list2 = list2->link;
    }
    else{
        merging = list1;
        list1 = list1->link;
    }

    while( list1 != NULL && list2 != NULL ){
        print_list(merging);
        if(list1->data > list2->data){
            merging->link = list2;
            list2 = list2->link;
        }
        else{
            merging->link = list1;
            list1 = list1->link;
        }
        merging = merging->link;
    }

    while( list1 != NULL ){
        print_list(merging);
        merging->link = list1;
        list1 = list1->link;
        merging = merging->link;
    }

    while( list2 != NULL ){
        print_list(merging);
        merging->link = list2;
        list2 = list2->link;
        merging = merging->link;
    }

    return merging;
}

int main(void){
    
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    int array1[4] = {7,5,3,1};
    int array2[3] = {5,4,2};

    head1 = consList(array1, 4);
    head2 = consList(array2, 3);

    print_list(head1);
    print_list(head2);

    ListNode *merging = NULL;
    merging = merge(head1, head2);

    print_list(merging);

    return 0;
}