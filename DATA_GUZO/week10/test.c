#include <stdio.h>  // 표준입출력 라이브러리
#include <stdlib.h> // 표준라이브러리
#include <math.h>   // 수학함수 pow사용
#include <string.h>
#define MAX_SIZE 20 // 스택의 최대 크기 설정

typedef struct {
    int data[MAX_SIZE]; // int 형 스택 데이터
    int top;            // int 형 스택 top
} stack_type;           // stack_type으로 정의

typedef stack_type* stack_ptr;
typedef char element;

void init(stack_ptr s) { // 스택을 초기화한다.
    s->top = -1;
}

int is_empty(stack_type s) { // 스택이 비었으면 true, 아니면 false
    return (s.top == -1);
}

int is_full(stack_type s) {  // 스택이 찼으면 true, 아니면 false
    return (s.top == (MAX_SIZE - 1));
}

void push(stack_ptr s, int val) {    // 스택에 추가한다.

    if (is_full(*s)) {               // 스택이 차있는지 검사
        printf("[PUSH]Error: stack full\n");
        return;
    }

    else {                           // 차있지 않으면 스택에 추가
        s->data[++s->top] = val;
    }
}

int pop(stack_ptr s) {   // 스택에서 top 내용을 반환

    if (is_empty(*s)) {  // 스택이 비었는지 검사
        printf("[POP]Error: stack empty\n");
        exit(1);
    }

    else {               // 아니면 내용을 반환
        //printf("pop 할거임 %c\n",s->data[s->top]);
        return s->data[s->top--];
    }
}

int peek(stack_type s) { // top 내용을 반환(제거되지 않음)
    if (is_empty(s)) {  // 스택이 비었는지 검사
        fprintf(stderr, "[PEEK]Error: stack empty\n");
        exit(1);
    }
    else {               // 아니면 내용을 반환(제거되지 않음)
        return s.data[s.top];
    }
}

void get_exp(char* exp) {    // 식을 입력받는다.
    printf("식 입력: ");
    gets(exp);              // gets를 통한 입력
}

char get_token(char* exp) {      // 호출시마다 토큰을 하나씩 리턴함
    static int get_index = 0;   // 정적변수로 호출시 변수 초기화 방지
    return exp[get_index++];    // 토큰을 반환함
}


int pattern_in_stack(char op) {
    switch (op) {
    case '(':
        return 0;
    case ')':
        return 4;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    
    }
    return -1;
}

<<<<<<< HEAD
void postifx(char iexp[], char pexp[]){

    int index = 0;
    char op = get_token(iexp);
=======


int pattern_out_stack(char op) {
    switch (op) {
    case '(':
        return 4;
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    
    }
    return -1;
}

void postfix3(char iexp[], char* pexp) {
    int p_index = 0;
   
    char ch, top_op;
    int len = strlen(iexp);

>>>>>>> 866cc8956a9a4292e75984740ded2e096f0cd996
    stack_type s;
    //int before_is_num = 0;
    //char numtemp[100];
 

    stack_type nums;
    init(&nums);
    
    stack_type tempStack;
    init(&tempStack);

 
    init(&s);
    for (int i = 0; iexp[i] != '\0'; i++) {
        ch = iexp[i];
        int token = pattern_out_stack(ch);
        //printf("%c : %d\n", ch, token);;
        if (ch == ')') {

<<<<<<< HEAD
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
=======

            if (!is_empty(nums)) {
                while (!is_empty(nums)) {
                    push(&tempStack, pop(&nums));
                    
                }
                while (!is_empty(tempStack)) {
                    pexp[p_index++] = pop(&tempStack);
                }
                pexp[p_index++] = ' ';
            }

            char left;
            while ((left = pop(&s)) != '(') {
                pexp[p_index++] = left;
                pexp[p_index++] = ' ';
       
            }
        }
        else if (token == -1) {

            
            push(&nums, ch);

            //pexp[p_index++] = ch;
            //pexp[p_index++] = ' ';
            //printf("큐 삽입 %c", ch); //큐에 삽입
        }
        else {

            if (!is_empty(nums)) {
                while (!is_empty(nums)) {
                    push(&tempStack, pop(&nums));

                }
                while (!is_empty(tempStack)) {
                    pexp[p_index++] = pop(&tempStack);
                }
                pexp[p_index++] = ' ';
            }
            


            while (!is_empty(s) && pattern_in_stack(peek(s)) >= token) {
                char temp = pop(&s);
                pexp[p_index++] = temp;
                pexp[p_index++] = ' ';
                printf("%c", temp);
>>>>>>> 866cc8956a9a4292e75984740ded2e096f0cd996
            }
            push(&s, ch);
        }
<<<<<<< HEAD
        else if(op == '*' || op == '/'){
            if (is_empty(s)){
                push(&s, op);
=======

    }
    if (!is_empty(nums)) {

        while (!is_empty(nums)) {
            push(&tempStack, pop(&nums));

        }
        while (!is_empty(tempStack)) {
            pexp[p_index++] = pop(&tempStack);
        }
        pexp[p_index++] = ' ';
    }

    while (!is_empty(s)) {
        char temp = pop(&s);
        pexp[p_index++] = temp;
        pexp[p_index++] = ' ';
        //printf("%c", temp);
    }
    pexp[p_index++] = '\0';

}



void postfix2(char iexp[], char* pexp) {
    int p_index = 0;
    char ch, top_op;
    int len = strlen(iexp);

    stack_type s;

    init(&s);

    for (int i = 0; i < len; i++) {
        ch = iexp[i];

        // 여는 괄호: 스택에 삽입
        // 우선순위 : 가장 낮음
        if (ch == '(') {
            push(&s, ch);
        }

        // 닫는 괄호: ( 나올때까지 pop 근데 is_empty일때 break
        else if (ch == ')') {

            top_op = pop(&s);

            while (top_op != '(')
            {
                pexp[p_index++] = top_op;
                top_op = pop(&s);
            }
        }

        else if (ch == '+' || ch == '-') {
            char peek_ch;
            while (!is_empty(s) && (peek_ch = peek(s)) != '+' && peek_ch != '-' && peek_ch != '(') {
                pexp[p_index++] = pop(&s);

>>>>>>> 866cc8956a9a4292e75984740ded2e096f0cd996
            }
            push(&s, ch);
            continue;
            /*
            if(is_empty(s)){
                push(&s, ch);
                continue;
            }

           else{
                while(!is_empty(s)){
<<<<<<< HEAD
                    if(peek(s) == '^'){
                        pexp[index++] = pop(&s);
=======

                    if ( peek(s) != '(' || peek(s) != ')' ){
                        pexp[p_index++] = pop(&s);
>>>>>>> 866cc8956a9a4292e75984740ded2e096f0cd996
                    }

                    else{
                        break;
                    }
                }
<<<<<<< HEAD
                push(&s, op);
            }
            else{
                push(&s, op);
=======

                push(&s, ch);
           }*/
        }

        else if (ch == '*' || ch == '/') {
            char peek_ch;
            while (!is_empty(s) && (peek_ch = peek(s)) != '+' && peek_ch != '-' && peek_ch != '(' && peek_ch != '*' && peek_ch != '/') {
                pexp[p_index++] = pop(&s);

            }
            push(&s, ch);

            /*

            if(is_empty(s)){
                push(&s, ch);
                continue;
>>>>>>> 866cc8956a9a4292e75984740ded2e096f0cd996
            }

            else{
                while(!is_empty(s)){
                    if (peek(s) == '*' || peek(s) == '/' || peek(s) == '^'){
                        pexp[p_index++] = pop(&s);
                    }

                    else{
                        break;
                    }
                }

                push(&s, ch);
            }*/
        }
<<<<<<< HEAD
        else if(op == '^'){
            push(&s, op);
        }
        else if(op == '('){
        }
        else if(op == ')'){
            while(!is_empty(s)){
                pexp[index++] = pop(&s);
=======

        else if (ch == '^') {
            char peek_ch;
            while (!is_empty(s) && (peek_ch = peek(s)) != '+' && peek_ch != '-' && peek_ch != '(' && peek_ch != '*' && peek_ch != '/' && peek_ch != '^') {
                pexp[p_index++] = pop(&s);

>>>>>>> 866cc8956a9a4292e75984740ded2e096f0cd996
            }
            push(&s, ch);
            continue;


        }
<<<<<<< HEAD
        else{
            pexp[index++] = op;
        }
        
        op = get_token(iexp);
    } while(op != '\0');

    while(!is_empty(s)){
        pexp[index++] = pop(&s);
=======

        else {
            pexp[p_index++] = ch;
        }
    }

    while (!is_empty(s)) {
        pexp[p_index++] = pop(&s);
>>>>>>> 866cc8956a9a4292e75984740ded2e096f0cd996
    }
    pexp[index] = '\0';
}

void postifx(char* iexp, char* pexp) {   // 중위식을 후위식으로 변환

    int p_index = 0;                    // 후위식의 인덱스
    char get_c = get_token(iexp);       // 토큰을 하나씩 받음
    stack_type s;                       // 스택 생성

    init(&s);                           // 스택 초기화

    do {
        if (get_c == '+' || get_c == '-') {  // 가장 낮은 중요도를 가짐
            if (is_empty(s)) {               // 스택이 비었는지 검사
                push(&s, get_c);            // 스택에 추가
            }
            else if (peek(s) == '*' || peek(s) == '/' || peek(s) == '^') {
                while (!is_empty(s)) {    // 스택이 비었는지 검사 후 중요도에 따라 제거
                    if (peek(s) == '*' || peek(s) == '/' || peek(s) == '^') {
                        pexp[p_index++] = pop(&s);  // 스택을 반환 후 제거
                    }
                }
                push(&s, get_c);    // 스택에 추가
            }
            else {
                push(&s, get_c);    // 스택에 추가
            }
        }
        else if (get_c == '*' || get_c == '/') {  // 두번째 중요도를 가짐
            if (is_empty(s)) {                   // 스택이 비었는지 검사
                push(&s, get_c);                // 스택에 추가
            }
            else if (peek(s) == '^') {            // 중요도에 따라 제거
                while (!is_empty(s)) {            // 스택이 비었는지 검사
                    if (peek(s) == '^') {         // 중요도에 따라 제거
                        pexp[p_index++] = pop(&s); // 후위식에 추가
                    }
                }
                push(&s, get_c);                // 스택에 추가
            }
            else {
                push(&s, get_c);                // 스택에 추가
            }
        }
        else if (get_c == '^') {                  // 가장 높은 중요도를 가짐
            push(&s, get_c);                    // 스택에 추가
        }
        else if (get_c == '(') {                  // 여는 괄호는 아무것도 하지않음
        }
        else if (get_c == ')') {                  // 닫는 괄호일 경우 스택을 모두 제거
            while (!is_empty(s)) {                // 빌때까지 반복
                pexp[p_index++] = pop(&s);      // 스택에서 반환 후 제거
            }
        }
        else {
            pexp[p_index++] = get_c;            // 후위식에 추가
        }

        get_c = get_token(iexp);                // 토큰을 새로 받음
    } while (get_c != '\0');                     // 입력값의 끝인지 검사

    while (!is_empty(s)) {                        // 스택이 비었는지 검사
        pexp[p_index++] = pop(&s);              // 빌때까지 후위식에 추가
    }
    pexp[p_index] = '\0';                       // 마지막에 NULL을 넣어줌
}

int paren_test(char* exp) {  // 괄호가 잘 되어있는지 판단

    char ch;
    int i = 0;

    int num[MAX_SIZE] = { 0, };

    stack_type s;   // 스택을 생성

    init(&s);       // 스택을 초기화

    while ((ch = exp[i++]) != '\0') {    // NULL이 나올때까지 반복

        if (ch == '(') {      // 여는 괄호 일 경우 스택에 추가
            push(&s, ch);
        }

        else if (ch == ')') { // 닫는 괄호 일 경우 스택에서 제거
            pop(&s);
        }
    }

    if (!is_empty(s)) {  // 스택이 비어있지 않은지 검사, 안비었으면 오류 출력
        fprintf(stderr, "Error: Encorrect exp\n");
        exit(1);
        return 1;
    }

    else {
        return 0;
    }
}

int eval(char exp[]) {

    stack_type s;

    stack_type temp;
    init(&temp);

    init(&s);
    

  
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];
        //ch가 0~9 까지 있다면
        if (ch == ' ') {
            continue;
        }


        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
        
            while('0'<=(ch=exp[i]) && ch <='9' ){
                push(&temp, (ch - '0'));
                i++;
            }
            int num = 0;
            int mul = 1;
            while (!is_empty(temp)) {
                num += mul * pop(&temp);
                mul *= 10;
            }
            //int value = ch - '0';
            push(&s, num);
        }

        //공백을 만나면

        else {
            int num2 = pop(&s);
            int num1 = pop(&s);

            if (ch == '+') {
                push(&s, num1 + num2);
            }
            else if (ch == '-') {
                push(&s, num1 - num2);
            }
            else if (ch == '*') {
                push(&s, num1 * num2);
            }
            else if (ch == '/') {
                push(&s, num1 / num2);
            }
            else if (ch == '^') {
                push(&s, pow(num1, num2));
            }
        }
    }

    return pop(&s);
}

int main(void) {
    char exp[MAX_SIZE];     // 입력될 식(중위식)
    char pexp[MAX_SIZE*2];    // 후위식

    memset(pexp, 0, MAX_SIZE * sizeof(char));

    get_exp(exp);                                  // 중위식 입력
    paren_test(exp);                               // 괄호가 올바른지 판단
    printf("중위식 11: %s\n", exp);
    postfix3(exp, pexp);                            // 중위식을 후위식으로 변환
    printf("후위식 : %s\n", pexp);
    printf("후위식 계산 결과 : %d\n",eval(pexp));   // 후위식을 계산

    return 0;
}