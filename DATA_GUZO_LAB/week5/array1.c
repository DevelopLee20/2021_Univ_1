#include <stdio.h>

// 1-a. 문제
#define MAX_TERMS 100

// term의 원소 타입
typedef struct {
    float coef; // 계수
    int expo; // 차수
} term_type;

typedef struct{
    // coef와 expo 쌍을 고차항 부터 저장함
    term_type terms[MAX_TERMS];
    // 다항식의 항 개수
    int num;
} poly;

// // 1-b. 문제

// poly p = {{{8,3},{7,1},{1,0}},3};

// // 1-c. 문제

// // int main(void){
// //     printf("%.0f", p.terms[1].coef);
// //     return 0;
// // }

// // 1-d. 문제

// poly q = {{{10,5},{2,3},{3,2},{6,1}},4};

// 1-e. 문제

// poly r = {{{10,5},{10,3},{3,2},{13,1},{1,0},5}};

// 1-f. 문제

poly poly_add(poly p, poly q){
    poly r;

    int dp=0, dq=0, dr=0, num=0;

    while( dp!=p.num && dq!=q.num ){
        
        if ( p.terms[dp].expo == q.terms[dq].expo ){
            r.terms[dr].coef = p.terms[dp].coef + q.terms[dq++].coef;
            r.terms[dr++].expo = p.terms[dp++].expo;
            num++;
        }

        else if ( p.terms[dp].expo > q.terms[dq].expo ){
            r.terms[dr++] = p.terms[dp++];
            num++;
        }

        else{
            r.terms[dr++] = q.terms[dq++];
            num++;
        }
    }

    if ( dp!=p.num ){
        for(int i=dp; i<p.num; i++){
            r.terms[dr++] = p.terms[dp];
            num++;
        }
    }

    if ( dq!=q.num ){
        for(int j=dq; j<q.num; j++){
            r.terms[dr++] = q.terms[dq++];
            num++;
        }
    }

    r.num = num;
    return r;
}

int main(void){

    poly p = {{{8,3},{7,1},{1,0}},3};
    poly q = {{{10,5},{2,3},{3,2},{6,1}},4};

    poly r = poly_add(p,q);

    for(int i=0; i<r.num; i++){
        printf("%.0f ",r.terms[i].coef);
    }

    return 0;
}