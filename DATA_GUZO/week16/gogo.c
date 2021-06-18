#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

        for(int i=0; i<s.top+1; i++){
            printf("%c ",s.data[i]);
        }

        printf("\nD: %s\n",post);
    }

    while(!is_empty(s))
        post[t_idx++] = pop(&s);

    post[t_idx] = '\0';
}

int main(void){

    char *exp = malloc(sizeof(char)*MAX_SIZE);
    char *post = malloc(sizeof(char)*MAX_SIZE);

    get_exp(exp);

    postfix(exp, post);

    printf("%s",post);

    return 0;
}