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

    if(head == NULL){ // (1)
        fprintf(stderr, "[get_entry] : list is empty");

        return 1;
    }

    else{ // (2)
        ListNode *p = head; // (3)

        while( --index ){ // (4)
            p = p->link;

            if( p == NULL ){ // (5)
                fprintf(stderr, "[get_entry] : list is shorter then index");
                
                return 1;
            }
        }

        return p->data; // (6)
    }
}

int list_sum(ListNode *list){

    ListNode *p = list; // (1)
    int sum = 0; // (2)

    while(p != NULL){ // (3)
        sum += p->data;
        p = p->link;
    }

    return sum; // (4)
}

ListNode* reverse(ListNode *head){

    ListNode *list = head; // (1)
    ListNode *reverse = NULL; // (2)
    ListNode *swap; // (3)

    while(list != NULL){ // (4)
        swap = reverse;       // reverse의 상태를 저장
        reverse = list;       // reverse에 list 상태를 저장
        list = list->link;    // list를 다음 노드로 넘긴다.
        reverse->link = swap; // 현재 리스트의 링크를 swap에 넘긴다.
    }

    return reverse; // (5)
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