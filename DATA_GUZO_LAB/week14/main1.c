#include <stdio.h>

void preorder(int T[], int idx){
    if( T[idx] != 0 ){
        printf("%d ", T[idx]);
        preorder(T, 2*idx);
        preorder(T, 2*idx+1);
    }
}

void inorder(int T[], int idx) {
    if ( T[idx] != 0 ) {
        inorder(T, 2 * idx);
        printf("%d ", T[idx]);
        inorder(T, 2 * idx + 1);
    }
}

void postorder(int T[], int idx) {
    if ( T[idx] != 0 ) {
        postorder(T, 2 * idx);
        postorder(T, 2 * idx + 1);
        printf("%d ", T[idx]);
    }
}

int main(void) {

    int T[32] = { 0,1,2,3,4,5,6,0,0,7,8,0,0,9,0,0 };

    printf("preorder: ");
    preorder(T, 1);
    printf("\ninorder: ");
    inorder(T, 1);
    printf("\npostorder: ");
    postorder(T, 1);

    return 0;
}