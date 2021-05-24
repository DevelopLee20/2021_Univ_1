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

int get_entry(ListNode *head, int index){

    if(head == NULL){
        fprintf(stderr, "[get_entry1] : list is empty");

        return 1;
    }

    else{
        ListNode *p = head;

        while( --index ){
            p = p->link;

            if( p == NULL ){
                fprintf(stderr, "[get_entry2] : list is shorter then index");
                
                return 1;
            }
        }

        return p->data;
    }
}

int list_sum(ListNode *list){

    ListNode *p = list;
    int sum = 0;

    while(p != NULL){
        sum += p->data;
        p = p->link;
    }

    return sum;
}

ListNode* reverse(ListNode *head){

    ListNode *list = head;
    ListNode *reverse = NULL;
    ListNode *swap;

    while(list != NULL){
        swap = reverse;
        reverse = list;
        list = list->link;
        reverse->link = swap;
    }

    return reverse;
}

int main(void){

    ListNode *list = NULL;

    list = insert_first(list, 10);
    list = insert_first(list, 20);
    list = insert_first(list, 30);
    list = delete_first(list);
    list = insert_first(list, 40);
    list = insert_first(list, 50);
    list = reverse(list);
    print_list(list);
    printf("%d\n", get_entry(list,3));
    printf("Summation of node values: %d\n", list_sum(list));

    return 0;
}