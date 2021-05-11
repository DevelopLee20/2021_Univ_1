#include <stdio.h>  // 표준입출력 라이브러리
#include <stdlib.h> // 표준라이브러리
#include <math.h>   // 수학함수 pow사용
#include <string.h> // strlen() 를 사용
#define MAX_SIZE 20 // 스택의 최대 크기 설정

typedef struct {
    int data[MAX_SIZE]; // int 형 스택 데이터
    int top;            // int 형 스택 top
} stack_type;           // stack_type으로 정의

typedef stack_type* stack_ptr;

void init(stack_ptr s){ // 스택을 초기화한다.
    s -> top = -1;
}

int is_empty(stack_type s){ // 스택이 비었으면 true, 아니면 false
    return (s.top == -1);
}

int is_full(stack_type s){  // 스택이 찼으면 true, 아니면 false
    return (s.top == (MAX_SIZE -1));
}

void push(stack_ptr s, int val){    // 스택에 추가한다.
   
    if (is_full(*s)){               // 스택이 차있는지 검사
        printf("[PUSH]Error: stack full\n");
        return;
    }

    else{                           // 차있지 않으면 스택에 추가
        s -> data[++s -> top] = val;
    }
}

int pop(stack_ptr s){   // 스택에서 top 내용을 반환
 
    if (is_empty(*s)){  // 스택이 비었는지 검사
        printf("[POP]Error: stack empty\n");
        exit(1);
    }

    else{               // 아니면 내용을 반환
        //printf("pop 할거임 %c\n",s->data[s->top]);
        return s->data[s->top--];
    }
}

int peek(stack_type s){ // top 내용을 반환(제거되지 않음)
    if( is_empty(s) ){  // 스택이 비었는지 검사
        fprintf(stderr, "[PEEK]Error: stack empty\n");
        exit(1);
    }
    else{               // 아니면 내용을 반환(제거되지 않음)
        return s.data[s.top];
    }
}

void get_exp(char *exp){    // 식을 입력받는다.
    printf("식 입력: ");
    gets(exp);              // gets를 통한 입력
}

char get_token(char *exp){      // 호출시마다 토큰을 하나씩 리턴함
    static int get_index = 0;   // 정적변수로 호출시 변수 초기화 방지
    return exp[get_index++];    // 토큰을 반환함
}

void postfix(char iexp[], char *pexp){
    int p_index = 0;            // 후위식 인덱스
    char op;                    // 판단할 토큰 변수
    char ch = get_token(iexp);  // 토큰을 하나씩 반환받음

    stack_type s;               // 스택 s 생성

    init(&s);                   // 스택 s 초기화

    while(ch != '\0'){          // 중위문의 끝에 왔을 경우 반복 종료

        if(ch=='('){            // 여는 괄호일 경우
            push(&s, ch);       // 스택에 추가
        }

        else if(ch==')'){       // 닫는 괄호일 경우
            op = pop(&s);       // 스택에서 제거

            while(op != '('){           // 여는 괄호가 나올때까지 반복
                pexp[p_index++] = op;   // 후위문에 추가함
                op = pop(&s);           // 스택에서 제거
            }
        }

        else if(ch == '+' || ch == '-'){
            
            if(is_empty(s)){        // 스택이 비었으면
                push(&s, ch);       // 스택에 추가
            }
            
            else{
                while(!is_empty(s)){
                    if(peek(s) != '(' && peek(s) != ')'){   // 괄호가 아니면
                        pexp[p_index++] = pop(&s);          // 후위문에 추가
                    }
                    else{
                        break;
                    }
                }
                push(&s, ch);   // 스택에 추가
            }
        }

        else if(ch == '*' || ch == '/' ){

            if(is_empty(s)){    // 스택이 비었으면
                push(&s, ch);   // 스택에 추가
            }

            else{
                while(!is_empty(s)){    // 연산순위에 따라서 조건을 나눔
                    if(peek(s) == '*' || peek(s) == '/' || peek(s) == '^'){
                        pexp[p_index++] = pop(&s);  // 후위문에 추가
                    }
                    else{
                        break;
                    }
                }
                push(&s, ch);   // 스택에 추가
            }
        }

        else if(ch == '^'){     // 제곱 기호 추가사항
            if(is_empty(s)){    // 스택이 비었으면
                push(&s, ch);   // 스택에 추가
            }

            else{
                while(!is_empty(s)){
                    if(peek(s) == '^'){
                        pexp[p_index++] = pop(&s);  // 후위문에 추가
                    }
                    else{
                        break;
                    }
                }
                push(&s, ch);   // 스택에 추가
            }
        }

        else{
            pexp[p_index++] = ch;   // 후위문에 추가
        }

        ch = get_token(iexp);   // 토큰을 다음 것을 받음
    }

    while(!is_empty(s)){    // 스택에 남은 요소를 모두 후위문에 전달
        pexp[p_index++] = pop(&s);
    }
    pexp[p_index] = '\0'; // 후위문 마지막에 NULL 문자를 입력
}

int paren_test(char *exp){  // 괄호가 잘 되어있는지 판단

    char ch;
    int i = 0;

    int num[MAX_SIZE] = {0,};

    stack_type s;   // 스택을 생성

    init(&s);       // 스택을 초기화

    while ((ch = exp[i++]) != '\0'){    // NULL이 나올때까지 반복

        if(ch == '('){      // 여는 괄호 일 경우 스택에 추가
            push(&s, ch);
        }

        else if(ch == ')'){ // 닫는 괄호 일 경우 스택에서 제거
            pop(&s);
        }
    }

    if (!is_empty(s)){  // 스택이 비어있지 않은지 검사, 안비었으면 오류 출력
        fprintf(stderr, "Error: Encorrect exp\n");
        exit(1);
        return 1;
    }

    else{
        return 0;
    }
}

int eval(char exp[]){

    stack_type s;

    init(&s);

    for(int i=0; i<strlen(exp); i++){
        char ch = exp[i];

        // 조건에 없는 기호가 발생한 경우 예외처리를 해준다.
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^'){
            int value = ch - '0';
            push(&s, value);
        }

        else{
            int num2 = pop(&s); // 두 변수의 순서를 바꾼다.
            int num1 = pop(&s); // 두 변수의 순서를 바꾼다.

            // 조건에 따라서 연산하도록 해준다.
            if ( ch == '+' ){
                push(&s, num1 + num2);
            }
            else if ( ch == '-' ){
                push(&s, num1 - num2);
            }
            else if ( ch == '*' ){
                push(&s, num1 * num2);
            }
            else if ( ch == '/' ){
                push(&s, num1 / num2);
            }
            else if ( ch == '^' ){
                push(&s, pow(num1, num2));
            }
        }
    }

    return pop(&s);
}

int main(void){
    char exp[MAX_SIZE];     // 입력될 식(중위식)
    char pexp[MAX_SIZE];    // 후위식

    memset(pexp, 0, MAX_SIZE*sizeof(char));

    get_exp(exp);                                  // 중위식 입력
    paren_test(exp);                               // 괄호가 올바른지 판단
    printf("중위식 : %s\n",exp); 
    postfix(exp, pexp);                            // 중위식을 후위식으로 변환
    printf("후위식 : %s\n",pexp);
    printf("후위식 계산 결과 : %d\n",eval(pexp));   // 후위식을 계산

    return 0;
}