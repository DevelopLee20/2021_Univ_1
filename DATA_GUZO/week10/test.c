#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 20

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack_type;

typedef stack_type* stack_ptr;

void init(stack_ptr s){
    s -> top = -1;
}

int is_empty(stack_type s){
    return (s.top == -1);
}

int is_full(stack_type s){
    return (s.top == (MAX_SIZE -1));
}

void push(stack_ptr s, int val){
   
    if (is_full(*s)){
        printf("Error: stack full\n");
        return;
    }

    else{
        s -> data[++s -> top] = val;
    }
}

int pop(stack_ptr s){
 
    if (is_empty(*s)){
        printf("Error: stack empty\n");
        printf("Unbalanced");
        exit(1);
    }

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

void get_exp(char *exp){
    printf("식 입력: ");
    gets(exp);
}

char get_token(char *exp){
    static int get_index = 0;
    return exp[get_index++];
}

void postifx(char iexp[], char pexp[]){

    int index = 0;
    char op = get_token(iexp);
    stack_type s;

    init(&s);

    do{
        if (op == '+' || op == '-'){
            if (is_empty(s)){
                push(&s, op);
            }
            else if(peek(s) == '*' || peek(s) == '/' || peek(s) == '^'){
                while(!is_empty(s)){
                    if(peek(s) == '*' || peek(s) == '/' || peek(s) == '^'){
                        pexp[index++] = pop(&s);
                    }
                }
                push(&s, op);
            }
            else{
                push(&s, op);
            }
        }
        else if(op == '*' || op == '/'){
            if (is_empty(s)){
                push(&s, op);
            }
            else if(peek(s) == '^'){
                while(!is_empty(s)){
                    if(peek(s) == '^'){
                        pexp[index++] = pop(&s);
                    }
                }
                push(&s, op);
            }
            else{
                push(&s, op);
            }
        }
        else if(op == '^'){
            push(&s, op);
        }
        else if(op == '('){
        }
        else if(op == ')'){
            while(!is_empty(s)){
                pexp[index++] = pop(&s);
            }
        }
        else{
            pexp[index++] = op;
        }
        
        op = get_token(iexp);
    } while(op != '\0');

    while(!is_empty(s)){
        pexp[index++] = pop(&s);
    }
    pexp[index] = '\0';
}

int eval(char *pexp){
    int i=0;

    stack_type s;

    init(&s);

    while(pexp[i] != '\0'){
        if(is_empty(s)){
            push(&s, pexp[i]);
        }
        else if(pexp[i] == '^'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, pow(b,a)+48);
        }
        else if(pexp[i] == '*'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, a*b+48);
        }
        else if(pexp[i] == '/'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, a/b+48);
        }
        else if(pexp[i] == '+'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, a+b+48);
        }
        else if(pexp[i] == '-'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, a-b+48);
        }
        else{
            push(&s, pexp[i]);
        }
        printf("t %c\n",peek(s));
        i += 1;
    }
    
    return pop(&s)-48;
}

int main(void){
    char exp[MAX_SIZE];
    char pexp[MAX_SIZE];

    get_exp(exp);
    printf("exp: %s\n",exp);
    postifx(exp, pexp);
    printf("pexp: %s\n",pexp);
    printf("결과: %d\n",eval(pexp));

    return 0;
}