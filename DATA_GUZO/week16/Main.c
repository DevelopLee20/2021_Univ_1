#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 70

typedef struct stack_type {
    int data[MAX_SIZE];
    int top;
} Stack_Type;

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} Tree_Node;

void init(Stack_Type *s){
    s->top = -1;
}

int is_empty(Stack_Type s){
    return (s.top == -1);
}

int is_full(Stack_Type s){
    return (s.top == (MAX_SIZE - 1));
}

void push(Stack_Type *s, int val){
    if(is_full(*s)){
        fprintf(stderr,"[PUSH] Stack is full\n");
        return;
    }
    s->data[++(s->top)] = val;
}

int pop(Stack_Type *s){
    if(is_empty(*s)){
        fprintf(stderr,"[POP] Stack is Empty\n");
        exit(1);
    }
    return s->data[s->top--];
}

int peek(Stack_Type s){
    if(is_empty(s)){
        fprintf(stderr,"[PEEK] Stack is empty\n");
        exit(1);
    }
    return s.data[s.top];
}

void get_exp(char *exp){ // exp 매개변수는 포인터로 받는다.
    gets(exp); // gets를 사용해 수식을 입력받는다.
}

void postfix(char *exp, char *post){

    int idx = 0, t_idx = 0; // 인덱스 변수

    Stack_Type s; // 스택을 선언

    init(&s); // 스택을 초기화

    while(exp[idx] != '\0'){ // 수식 배열이 null이 될때까지 반복

        if( exp[idx] == '(' )
            push(&s, exp[idx]);

        else if( exp[idx] == ')' ){
            while(!is_empty(s)){
                
                if( peek(s) != '(' )
                    post[t_idx++] = pop(&s);
                else{
                    pop(&s);
                    break;
                }
            }
        }

        else if( exp[idx] == '+' || exp[idx] == '-' ){

            post[t_idx++] = ' ';

            while(!is_empty(s)){

                if( peek(s) != '(' && peek(s) != ')' )
                    post[t_idx++] = pop(&s);
                else
                    break;
            }
            push(&s, exp[idx]);
        }

        else if( exp[idx] == '*' || exp[idx] == '/' ){

            post[t_idx++] = ' ';

            while(!is_empty(s)){

                if( peek(s) != '(' && peek(s) != ')' && peek(s) != '+' && peek(s) != '-' )
                    post[t_idx++] = pop(&s);
                else
                    break;
            }
            push(&s, exp[idx]);
        }

        else if( exp[idx] == '^' ){

            post[t_idx++] = ' ';

            while(!is_empty(s)){

                if( peek(s) == '^' )
                    post[t_idx++] = pop(&s);
                else
                    break;
            }
            push(&s, exp[idx]);
        }

        else
            post[t_idx++] = exp[idx];
        
        idx++;
    }

    while(!is_empty(s))
        post[t_idx++] = pop(&s);

    post[t_idx] = '\0'; // 마지막에 null을 작성해서 끝을 알려준다.
}

Tree_Node* get_node(){

    Tree_Node *node = (Tree_Node*)malloc(sizeof(Tree_Node));

    node->left = NULL;
    node->right = NULL;

    return node;
}

typedef struct stack_type1 {
    Tree_Node *data[MAX_SIZE];
    int top;
} StackType;

void init1(StackType *s){
    s->top = -1;
}

int is_empty1(StackType s){
    return (s.top == -1);
}

Tree_Node* pop1(StackType *s){
    if(is_empty1(*s)){
        fprintf(stderr,"[POP] Stack is Empty\n");
        exit(1);
    }
    return s->data[s->top--];
}

int is_full1(StackType s){
    return (s.top == (MAX_SIZE - 1));
}

void push1(StackType *s, Tree_Node *val){
    if(is_full1(*s)){
        fprintf(stderr,"[PUSH] Stack is full\n");
        return;
    }
    s->data[++(s->top)] = val;
}

Tree_Node* const_Etree(char *T){
    
    StackType s; // 스택을 선언한다.

    int idx = 0; // 인덱스 변수
    char number[10];
    int num_idx = 0;
    int num;

    init1(&s); // 스택 초기화

    while(T[idx] != '\0'){ // 배열이 null을 만날때까지 반복

        if(isdigit(T[idx])){ // 요소가 숫자일 경우
            number[num_idx++] = T[idx]; // number 배열에 추가
        }

        else if(T[idx] == ' ' && num_idx != 0){ // 요소가 공백이거나 숫자 인덱스가 0이 아니면
            Tree_Node *node = get_node(); // 노드를 생성한 후
            sscanf(number,"%d",&num); // 1자리수 이상의 숫자를
            node->data = num; // node의 데이터에 저장한다.
            
            for(int i=0; i<=num_idx; i++){ // 배열을 초기화
                number[i] = '\0';
            }
            num_idx = 0; // 인덱스를 초기화
            push1(&s, node); // 생성한 노드를 스택에 push
        }

        else if(T[idx] == ' '){}

        else{

            if(num_idx != 0){
                Tree_Node *node = get_node(); // 노드를 생성
                sscanf(number,"%d",&num); // 1자리수 이상의 숫자를
                node->data = num; // node의 데이터에 저장한다.
                
                for(int i=0; i<=num_idx; i++){ // 배열을 초기화
                    number[i] = '\0';
                }
                num_idx = 0; // 인덱스를 초기화
                push1(&s, node); // 생성한 노드를 스택에 push
            }

            Tree_Node *node = get_node(); // 노드를 생성
            node->right = pop1(&s); //
            node->left = pop1(&s);
            node->data = T[idx]; // 연산자를 data에 대입
            push1(&s, node); 
        }
        idx++; // 배열 인덱스를 1 증가
    }
    return pop1(&s); // 생성된 트리를 반환한다.
}

Tree_Node* cons_exptree(char *post){

    Tree_Node *t = const_Etree(post); // 생성된 수식 트리 반환

    return t;
}

int eval(Tree_Node *T){

    if (T == NULL){
        return 0;
    }

    if (T->left == NULL && T->right == NULL){
        return T->data; // 잎노드일 경우 값을 반환
    }

    else{

        int oper_1 = eval(T->left);  // 첫번째 숫자를 저장
        int oper_2 = eval(T->right); // 두번째 숫자를 저장
        
        switch (T->data) // 데이터(연산자)에 따라 다른 결과를 반환
        {
        case '+':
            return oper_1 + oper_2;
            break;
        case '-':
            return oper_1 - oper_2;
            break;
        case '/':
            return oper_1 / oper_2;
            break;
        case '*':
            return oper_1 * oper_2;
            break;
        case '^':
            return pow(oper_1,oper_2); // 추가한 제곱 연산자
            break;
        }
    }
    return 0;
}

int main(void){

    char *exp = malloc(sizeof(char)*MAX_SIZE);
    char *post = malloc(sizeof(char)*MAX_SIZE);

    printf("수식입력: ");
    get_exp(exp);

    postfix(exp, post);

    Tree_Node *t = cons_exptree(post);

    printf("후위식  :%s\n", post);
    printf("계산결과: %d", eval(t));

    return 0;
}