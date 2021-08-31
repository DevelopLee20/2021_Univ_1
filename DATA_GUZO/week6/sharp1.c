#include <stdio.h>
#include <math.h> // pow 제곱함수 사용을 위한 라이브러리
#define MAX_TERMS 100 // 최대

typedef struct{
    float coef; // 계수
    int expo; // 차수
} term_type;

typedef struct{
    term_type terms[MAX_TERMS];
    int num; // 다항식 개수
} poly;

void print_poly(poly p){
    int i = 0;

    // 항의 개수 만큼 반복함
    for(i=0; i<p.num; i++){
        if (p.terms[i].expo == 0){ // 상수항일 경우 반복을 종료함
            i = i; // i가 변경되지 않게 함 (사실 필요없음)
            break; // 반복 종료
        }

        // 만약 항의 개수가 상수항 출력만 남은 경우을 대비해 출력을 조절한다.
        if (i == p.num-1) 
            printf("%.0fx^%d ",p.terms[i].coef,p.terms[i].expo);
        else    
            printf("%.0fx^%d + ",p.terms[i].coef,p.terms[i].expo);
    }
    // 마지막 항은 뒤에 + 가 생기지 않게 다르게 출력한다.
    if (p.terms[i].coef != 0)
        printf("%.0f",p.terms[i].coef);
    printf("\n");
}

poly sub_poly(poly p1, poly p2){
    poly p3;

    int dp=0, dq=0, dr=0, num=0;

    while( dp!=p1.num && dq!=p2.num ){
        
        // 차수가 같으면 서로 빼준다.
        if ( p1.terms[dp].expo == p2.terms[dq].expo ){
            p3.terms[dr].coef = p1.terms[dp].coef - p2.terms[dq++].coef;
            p3.terms[dr++].expo = p1.terms[dp++].expo;
            num++;
        }

        else if ( p1.terms[dp].expo > p2.terms[dq].expo ){
            p3.terms[dr++] = p1.terms[dp++];
            num++;
        }

        else{
            p3.terms[dr++] = p2.terms[dq++];
            num++;
        }
    }

    if ( dp!=p1.num ){
        for(int i=dp; i<p1.num; i++){
            p3.terms[dr++] = p1.terms[dp];
            num++;
        }
    }

    if ( dq!=p2.num ){
        for(int j=dq; j<p2.num; j++){
            p3.terms[dr++] = p2.terms[dq++];
            num++;
        }
    }

    p3.num = num;
    return p3; // 결과 값을 poly 구조체로 리턴한다.

}

// x값을 주었을때 항의 계산값을 출력한다.
int eval_poly(poly p, int x){
    int result = 0;
    for(int i=0; i<p.num; i++){
        // pow를 사용해 제곱을 해준다.
        result += (int)p.terms[i].coef * (int)pow(x,p.terms[i].expo);
    }
    return result;
}

int main(void){
    // 처음 다항식 2개를 초기화
    poly p1 = {{{8,3},{7,1},{1,0}},3};
    poly p2 = {{{10,5},{2,3},{3,2},{6,1}},4};

    // 함수를 사용해 반환된 poly 구조체를 저장
    poly p3 = sub_poly(p1,p2);
    
    // 각항을 출력해준다.
    print_poly(p1);
    print_poly(p2);
    print_poly(p3);

    int x = 1; // x의 값은 1이다.
    // x값이 주어졌을때 연산 값을 저장한다.
    int res = eval_poly(p3,x);
    printf("\np3 수식의 x 값이 %d 일때 값은",x);
    printf("\n%d 이다.\n",res);

    x = 2; // x의 값은 2이다.
    res = eval_poly(p3,x);
    printf("\np3 수식의 x 값이 %d 일때 값은",x);
    printf("\n%d 이다.\n",res);

    x = 3; // x의 값은 3이다.
    res = eval_poly(p3,x);
    printf("\np3 수식의 x 값이 %d 일때 값은",x);
    printf("\n%d 이다.\n",res);

    return 0;
}