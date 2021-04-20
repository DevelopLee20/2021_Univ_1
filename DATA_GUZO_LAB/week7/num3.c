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
        printf("Error: stack full\n");
        return;
    }

    // val 값을 저장하고, top 위치를 한칸 높인다.
    else{
        s -> data[++s -> top] = val;
    }
}

int pop(stack_ptr s){

    // 최종의 스택이 비어있으면, 언발란스를 출력한다.   
    if (is_empty(*s)){
        printf("Error: stack empty\n");
        printf("Unbalanced");
        exit(1);
    }

    // 스택이 비어있지 않으면, 값을 리턴하고, top 위치를 하나 줄인다.
    else{
        return s->data[s->top--];
    }
}

// 수식의 괄호 사용이 올바른지 테스트 하는 함수 작성
int paren_test(char exp[]){

    // 변수 선언 구간
    char ch;
    int i = 0;

    // stack_type을 s로 선언한다.
    stack_type s;

    // 스택을 초기화 한다.
    init(&s);

    // exp에 저장된 값의 끝까지 반복한다.
    while ((ch = exp[i++]) != '\0'){

        // 여는 괄호인 경우 스택에 push 한다.
        if(ch == '('){
            push(&s, ch);
        }

        // 닫는 괄호인 경우 스택에 pop 한다.
        else if(ch == ')'){
            pop(&s);
        }
    }

    // 최종적으로 스택이 비어있으면, return 1을 한다.
    if (is_empty(s)){
        return 1;
    }

    // 비어있지 않으면, return 0을 한다.
    else{
        return 0;
    }
}

int is_palindrome(char str[], int n){

    int i = 0;
    int mid; // 중앙값을 저장하는 변수

    stack_type s; // 스택 생성

    init(&s); // 스택 초기화

    // 저장할 부분까지 push 한다.
    for(int i=0; i<n/2; i++){
        push(&s,str[i]);
    }

    // 홀수여서 중앙값을 비교하지 않을 경우를 위해 mid 값을 조절함
    if(n % 2 == 0)
        mid = n/2; // mid
    else
        mid = n/2+1; // mid + 1

    // 뒤에 비교할 부분을 pop 해서 비교한다.
    for(int i=mid; i<n; i++){
        if(pop(&s) != str[i]){
            return 0;
        }   
    }
    return 1;
}

int main(void){

    // 판단할 괄호 문장을 exp에 저장한다.
    char exp[] = "palindrome";

    // exp 문자열의 길이를 저장한다.
    int n = sizeof(exp) - 1;

    if(is_palindrome(exp,n)){
        printf("%s is palindrome",exp);
    }
    else{
        printf("%s is NOT palindrome",exp);
    }

    return 0;
}