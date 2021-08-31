#include <stdio.h>  // 표준입출력 라이브러리
#include <stdlib.h> // 표준 라이브러리

// 덱의 최대 사이즈 설정
#define MAX_DEQUE_SIZE 10

// 덱의 데이터 타입을 설정
typedef int element;

typedef struct{ // 덱의 구조체 선언
    element data[MAX_DEQUE_SIZE];
    int front, rear;
} DequeType; // DequeType으로 이름을 변경

void init_deque(DequeType *d){ // 덱을 초기화
    d->front = 0; // front를 초기화
    d->rear = 0;  // rear을 초기화
}

int is_empty(DequeType *d){ // 덱이 비어있는지 검사
    return (d->front == d->rear);
}

int is_full(DequeType *d){ // 덱이 꽉 차있는지 검사
    return ((d->rear + 1) % MAX_DEQUE_SIZE == d->front);
}

void add_rear(DequeType *d, int seed){ // rear 위치에 요소를 추가
    if(is_full(d)){ // 꽉 차있으면 오류 발생
        fprintf(stderr, "[enqueue] 에러: 큐가 포화상태입니다.\n");
        exit(1);
    }
    // rear을 1 더해서 데이터를 저장함
    // 큐의 enqueue와 같은 코드이다.
    d -> rear = (d->rear + 1) % MAX_DEQUE_SIZE;
    d -> data[d->rear] = seed;
}

element delete_front(DequeType *d){
    if(is_empty(d)){
        fprintf(stderr, "[dequeue] 에러: 큐가 공백상태입니다.\n");
        exit(1);
    }

    // front를 1 더해서 그 값을 출력
    // 큐의 dequeue와 같은 코드이다.
    d -> front = (d->front + 1) % MAX_DEQUE_SIZE;
    return d -> data[d->front];
}

element get_front(DequeType *d){ // front 위치의 요소 리턴
    if(is_empty(d)){
        fprintf(stderr, "[peek] 에러: 큐가 비어있습니다.\n");
        exit(1);
    }
    return d->data[(d->front + 1) % MAX_DEQUE_SIZE];
}

element delete_rear(DequeType *d){ // rear 위치의 요소 제거
    if(is_empty(d)){
        fprintf(stderr, "[delete_rear] 에러: 큐가 공백상태입니다.");
    }
    int seed = d->rear; // seed로 지울 값의 인덱스를 저장
    // rear을 조정해준다.
    d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return d->data[seed]; // seed 인덱스의 값을 삭제한다.
}

// front 위치에 요소를 추가
void add_front(DequeType *d, element seed){
    if(is_full(d)){
        fprintf(stderr, "[add_front] 에러: 큐가 포화상태입니다.");
    }
    // seed 값을 front 위치에 추가해준다.
    d->data[d->front] = seed;
    d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

// rear 위치의 요소를 반환
element get_rear(DequeType *d){
    if(is_empty(d)){
        fprintf(stderr, "[get_rear] 에러: 큐가 고백상태입니다.");
    }
    return d->data[d->rear];
}

// 앞 뒤가 같은지 판단한 후 그 결과를 리턴한다.
int is_palin(DequeType *d, char s[]){

    char a, b; // 비교할 값 2개 저장
    int i = 0; // 인덱스 저장
    
    while(s[i] != '\0'){ // NULL이 나올떄까지 반복
        add_rear(d, s[i++]); // rear위치에 모두 더해준다.
    }

    while(1){

        if(!is_empty(d)){ // 비어있지 않으면 front 위치에서 요소 하나 가져옴
            a = get_front(d);
        }
        else{
            return 1;
        }
        
        if(!is_empty(d)){ // 비어있지 않으면 rear 위치에서 요소 하나를 가져옴
            b = get_rear(d);
        }
        else{
            return 1;
        }

        if(a == b){ // 요소 2개를 비교해서 같으면 둘 다 제거한다.
            delete_front(d);

            if(!is_empty(d)){ // 전체 길이가 홀수일 경우를 대비
                delete_rear(d); 
            }
        }
        else{
            return 0;
        }
    }
}

int main(void){

    DequeType d; // 덱 d를 선언

    init_deque(&d); // 덱 d를 초기화

    char s[20];

    while(1){
        printf("Word: ");
        scanf("%s",&s);

        if(is_palin(&d, s)){
            printf("%s is Palindrome!\n",s);
        }
        else{
            printf("%s is not Palindrome!\n",s);
        }
    }

    return 0;     
}