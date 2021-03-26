#include <stdio.h>

typedef struct
{
    double coef[100];
    int degree;
}poly;

poly poly_add(poly p, poly q){

    poly r;

    int pd = p.degree;
    int qd = q.degree;

    r.degree = p.degree > p.degree ? p.degree : q.degree;
    
    int ind = 0; int ip = 0; int iq = 0;

    while (ind != 6){
        if (pd>qd){
            r.coef[ind++] = p.coef[ip++];
            pd--;
        }
        else if (pd<qd){
            r.coef[ind++] = q.coef[iq++];
            qd--;
        }
        else{
            r.coef[ind++] = q.coef[iq++] + p.coef[ip++];
        }
    }

    return r;
}

int main(){
    poly p = {{8.0,0.0,7.0,1.0},3};
    poly q = {{10.0,0.0,0.0,3.0,6.0,0.0},5};
    poly r = poly_add(p,q);

    printf("degree: %d\n",r.degree);

    for(int i=0; i<r.degree; i++){
        printf("%0.lf, ",r.coef[i]);
    }
    printf("%0.lf",r.coef[r.degree]);

    return 0;
}