#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

display(QueueType q){
    for(int i=q.front+1; i<q.rear+1; i++){
        printf("[%d] ",q.data[i]);
    }
}

int main(void){

}