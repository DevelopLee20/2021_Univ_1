#include <stdio.h>

#define MAX_TERMS 100

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

    int i=0;

    for(i=0; i<r.num; i++){
        if (r.terms[i].expo == 0){
            i = i;
            break;
        }
        printf("%.0fx^%d + ",r.terms[i].coef,r.terms[i].expo);
    }

    printf("%.0f",r.terms[i].coef);

    return 0;
}