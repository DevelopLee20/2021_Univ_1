// 헤더파일 stdlib.h를 include 해서
// exit(1) : 강제종료를 사용할 수 있도록 한다.
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

// stack_type을 선언한다.
typedef struct {
    int data[MAX_SIZE];
    int top;
} stack_type;

// stack_type의 포인터를 stack_ptr로 선언한다.
typedef stack_type* stack_ptr;

// init 함수로 스택의 top을 초기화 한다.
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
    if( is_empty(s) ){
        fprintf(stderr, "Error: stack empty\n");
        exit(1);
    }
    else{
        return s.data[s.top];
    }
}

int remove_multiples(int num){
    int result = 0;             // 결과값 반환 변수
    int i = 0;                  // push된 개수 체크 변수
    int add = 1;                // 자리수를 조정할 변수
    int ch;                     // pop한 숫자를 저장할 변수
    int check[MAX_SIZE] = {0,}; // 중복체크를 할 배열
    int n_c = 0;                // 고유 숫자의 개수 인덱스 저장 변수
    int checker;                // boolean형처럼 판단할 변수

    stack_type s;   

    init(&s);

    // 10으로 나눈 나머지들을 push 해준다.
    while( num > 0 ){
        push(&s, num%10);
        num /= 10;
        i++;
    }

    // pop한 데이터를 기반으로 중복을 판단한다.
    for(int j=0; j<i; j++){

        checker = 1;
        ch = pop(&s);

        for(int k=0; k<n_c; k++){

            if (check[k] == ch){
                checker = 0;
                break;
            }
        }

        if (checker){
            check[n_c++] = ch;
            add *= 10;
        }
    }

    add /= 10;

    // 자리수를 조절하면서 result에 더해준다.
    for(int p=0; p<n_c; p++){
        result += check[p]*add;
        add /= 10;
    }

    // 결과값을 반환한다.
    return result;
}

int main(void){
    int num = 11222344;

    printf("%d -> %d\n", num, remove_multiples(num));

    return 0;
}