#include <stdio.h>
#define MAX_SIZE 20
#include <stdlib.h>

typedef struct{
    int data[20];
    int top;
}stack_type;

typedef stack_type* stack_ptr;

void init(stack_ptr s){
    s -> top = -1;
}

// top이 -1이면 스택이 비어있음을 리턴한다.
int is_empty(stack_type s){
    return (s.top == -1);
}

// top의 인덱스가 최상단일 경우 1을 리턴한다.
int is_full(stack_type s){
    return (s.top == (MAX_SIZE -1));
}

void push(stack_ptr s, int val){

    // 스택이 꽉 찼을경우 오류를 출력한다.    
    if (is_full(*s)){
        fprintf(stderr,"Error: stack full\n");
        return;
    }

    // val 값을 저장하고, top 위치를 한칸 높인다.
    else{
        s -> data[++s -> top] = val;
    }
}

int pop(stack_ptr s){

    if (is_empty(*s)){
        fprintf(stderr,"Error: stack empty\n");
        exit(1);
    }

    // 스택이 비어있지 않으면, 값을 리턴하고, top 위치를 하나 줄인다.
    else{
        return s->data[s->top--];
    }
}

int peek(stack_type s){
    if(is_empty(s)){
        fprintf(stderr, "Error: stack empty\n");
        exit(1);
    }
    else{
        return s.data[s.top];
    }
}

int remove_multiples(int num){
    stack_type s;

    init(&s);

    int result = 0;

    while (num > 0){
        int get = num % 10;
        num = num / 10;

        if (is_empty(s)){
            push(&s, get);
        }

        else if (peek(s) != get){
            push(&s, get);
        }
    }

    while(!is_empty(s)){
        result *= 10;
        result += pop(&s);
    }

    return result;
}

int main(void){
    int num = 11222334;

    printf("%d",remove_multiples(num));

    return 0;
}