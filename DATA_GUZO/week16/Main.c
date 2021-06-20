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

typedef union{
    int operand;
    char operator;
} element;

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

void get_exp(char *exp){
    gets(exp);
}

void postfix(char *exp, char *post){

    int idx = 0, t_idx = 0;
    char op;

    Stack_Type s;

    init(&s);

    while(exp[idx] != '\0'){

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

    post[t_idx] = '\0';
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
    
    StackType s;
    int idx = 0;
    char number[10];
    int num_idx = 0;
    int num;

    init1(&s);

    while(T[idx] != '\0'){

        if(isdigit(T[idx])){
            number[num_idx++] = T[idx];
        }

        else if(T[idx] == ' ' && num_idx != 0){
            Tree_Node *node = get_node();
            sscanf(number,"%d",&num);
            node->data = num;
            
            for(int i=0; i<=num_idx; i++){
                number[i] = '\0';
            }
            num_idx = 0;
            push1(&s, node);
        }

        else if(T[idx] == ' '){}

        else{

            if(num_idx != 0){
                Tree_Node *node = get_node();
                sscanf(number,"%d",&num);
                node->data = num;
                
                for(int i=0; i<=num_idx; i++){
                    number[i] = '\0';
                }
                num_idx = 0;
                push1(&s, node);
            }

            Tree_Node *node = get_node();
            node->right = pop1(&s);
            node->left = pop1(&s);
            node->data = T[idx];
            push1(&s, node);
        }
        idx++;
    }
    return pop1(&s);
}

Tree_Node* cons_exptree(char *post){

    Tree_Node *t = const_Etree(post);

    return t;
}

int eval(Tree_Node *T){

    if (T == NULL){
        return 0;
    }

    if (T->left == NULL && T->right == NULL){
        return T->data;
    }

    else{

        int oper_1 = eval(T->left);
        int oper_2 = eval(T->right);
        
        switch (T->data)
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
            return pow(oper_1,oper_2);
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