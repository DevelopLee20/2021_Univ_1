#include <stdio.h>
#include <stdlib.h>

struct NODE{
    struct NODE *next;
    int data;
};

int main(void){
    struct NODE *head = malloc(sizeof(struct NODE));
    struct NODE *node1 = malloc(sizeof(struct NODE));
    struct NODE *node2 = malloc(sizeof(struct NODE));
    head->next = node1;
    node1->next = node2;
    node1->data = 20;
    node2->data = 40;

    node2->next = NULL;

    struct NODE *carry = head->next;

    while ( carry != NULL ){
        printf("%d\n",carry->data);
        carry = carry->next;
    }

    free(head);
    free(node1);
    free(node2);
    free(carry);

    return 0;
}