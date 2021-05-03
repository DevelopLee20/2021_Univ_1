#include <stdio.h>
#define MAX_SIZE 20
#include <stdlib.h>

typedef struct{
    int data[20];   // 스택의 크기 설정
    int top;        // 스택의 최상단 인덱스
}stack_type;

typedef stack_type* stack_ptr;

void init(stack_ptr s){ // 스택을 초기화 한다.
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

int peek(stack_type s){ // 최상단 top 위치에 있는 스택을 리턴한다.
    if(is_empty(s)){
        fprintf(stderr, "Error: stack empty\n");
        exit(1);
    }
    else{
        return s.data[s.top];
    }
}

int remove_multiples(int num){
    stack_type s;                    // 스택 생성

    init(&s);                        // 스택 초기화

    int result = 0;                  // 결과값을 반환하기 위한 변수

    while (num >= 0){                // 숫자가 0보다 작을때 
        int get = num % 10;          // 첫번째 자리의 숫자를 저장힌다.
        num = num / 10;              // 숫자를 한 자리수 줄인다.

        if (is_empty(s)){            // 스택이 비어있으면 push
            push(&s, get);           // push하면 스택이 하나 늘어난다.
        }

        else if (peek(s) != get){    // 스택에 숫자가 있을때 넣을 숫자와 같지 않으면
            push(&s, get);           // push 해준다.
        }
    }

    while(!is_empty(s)){             // 스택이 비어질 때 까ㅋ지 반복한다.
        result *= 10;                // 10을 곱해주어서 자리수를 조절한다.
        result += pop(&s);           // pop해서 값을 더해준다.
    }

    return result;                   // 결과값을 반환한다.
}

int main(void){
    int num = 11222334;    // 숫자를 입력한다.

    printf("%d => %d", num, remove_multiples(num));

    return 0;
}