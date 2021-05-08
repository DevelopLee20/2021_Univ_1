#include <stdio.h>  // 표준입출력 라이브러리
#include <stdlib.h> // 표준라이브러리
#include <math.h>   // 수학함수 pow사용
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
        printf("Error: stack full\n");
        return;
    }

    else{                           // 차있지 않으면 스택에 추가
        s -> data[++s -> top] = val;
    }
}

int pop(stack_ptr s){   // 스택에서 top 내용을 반환
 
    if (is_empty(*s)){  // 스택이 비었는지 검사
        printf("Error: stack empty\n");
        exit(1);
    }

    else{               // 아니면 내용을 반환
        return s->data[s->top--];
    }
}

int peek(stack_type s){ // top 내용을 반환(제거되지 않음)
    if( is_empty(s) ){  // 스택이 비었는지 검사
        fprintf(stderr, "Error: stack empty\n");
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

void postifx(char *iexp, char *pexp){   // 중위식을 후위식으로 변환

    int p_index = 0;                    // 후위식의 인덱스
    char get_c = get_token(iexp);       // 토큰을 하나씩 받음
    stack_type s;                       // 스택 생성

    init(&s);                           // 스택 초기화

    do{
        if (get_c == '+' || get_c == '-'){  // 가장 낮은 중요도를 가짐
            if (is_empty(s)){               // 스택이 비었는지 검사
                push(&s, get_c);            // 스택에 추가
            }
            else if(peek(s) == '*' || peek(s) == '/' || peek(s) == '^'){
                while(!is_empty(s)){    // 스택이 비었는지 검사 후 중요도에 따라 제거
                    if(peek(s) == '*' || peek(s) == '/' || peek(s) == '^'){
                        pexp[p_index++] = pop(&s);  // 스택을 반환 후 제거
                    }
                }
                push(&s, get_c);    // 스택에 추가
            }
            else{
                push(&s, get_c);    // 스택에 추가
            }
        }
        else if(get_c == '*' || get_c == '/'){  // 두번째 중요도를 가짐
            if (is_empty(s)){                   // 스택이 비었는지 검사
                push(&s, get_c);                // 스택에 추가
            }
            else if(peek(s) == '^'){            // 중요도에 따라 제거
                while(!is_empty(s)){            // 스택이 비었는지 검사
                    if(peek(s) == '^'){         // 중요도에 따라 제거
                        pexp[p_index++] = pop(&s); // 후위식에 추가
                    }
                }
                push(&s, get_c);                // 스택에 추가
            }
            else{
                push(&s, get_c);                // 스택에 추가
            }
        }
        else if(get_c == '^'){                  // 가장 높은 중요도를 가짐
            push(&s, get_c);                    // 스택에 추가
        }
        else if(get_c == '('){                  // 여는 괄호는 아무것도 하지않음
        }
        else if(get_c == ')'){                  // 닫는 괄호일 경우 스택을 모두 제거
            while(!is_empty(s)){                // 빌때까지 반복
                pexp[p_index++] = pop(&s);      // 스택에서 반환 후 제거
            }
        }
        else{
            pexp[p_index++] = get_c;            // 후위식에 추가
        }
        
        get_c = get_token(iexp);                // 토큰을 새로 받음
    } while(get_c != '\0');                     // 입력값의 끝인지 검사

    while(!is_empty(s)){                        // 스택이 비었는지 검사
        pexp[p_index++] = pop(&s);              // 빌때까지 후위식에 추가
    }
    pexp[p_index] = '\0';                       // 마지막에 NULL을 넣어줌
}

int eval(char *pexp){   // 후위식을 계산
    int i=0;             

    stack_type s;       // 스택을 생성

    init(&s);           // 스택을 초기화

    // 알고리즘: char형으로 저장되어있는 데이터는 int형으로 표현하려면 -48을 해주면 된다.
    // pop할 값에 -48을 해주어 연산한 후, 다시 저장할 때는 +48을 해준다.
    // 그 후 마지막 연산시에 -48을 해서 반환한다.
    while(pexp[i] != '\0'){
        if(is_empty(s)){
            push(&s, pexp[i]);
        }
        else if(pexp[i] == '^'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, pow(b,a)+48); // 제곱 내장 함수 사용
        }
        else if(pexp[i] == '*'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, b*a+48);
        }
        else if(pexp[i] == '/'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, b/a+48);
        }
        else if(pexp[i] == '+'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, b+a+48);
        }
        else if(pexp[i] == '-'){
            int a = pop(&s)-48;
            int b = pop(&s)-48;
            push(&s, b-a+48);
        }
        else{
            push(&s, pexp[i]);  // 마지막 연산
        }
        i += 1;
    }
    
    return pop(&s)-48;  // -48을 해준 후 반환
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

int main(void){
    char exp[MAX_SIZE];     // 입력될 식(중위식)
    char pexp[MAX_SIZE];    // 후위식

    get_exp(exp);                                  // 중위식 입력
    paren_test(exp);                               // 괄호가 올바른지 판단
    printf("중위식 : %s\n",exp); 
    postifx(exp, pexp);                            // 중위식을 후위식으로 변환
    printf("후위식 : %s\n",pexp);
    printf("후위식 계산 결과 : %d\n",eval(pexp));   // 후위식을 계산

    return 0;
}