#include <stdio.h>

// 전위 순회
void preorder(int T[], int idx){

    if( T[idx] != 0 ){
        printf("%d ", T[idx]);
        preorder(T, 2*idx);   // 왼쪽 노드
        preorder(T, 2*idx+1); // 오른쪽 노드
    }
}

// 중위 순회
void inorder(int T[], int idx){

    if( T[idx] != 0 ){
        inorder(T, 2*idx);
        printf("%d ", T[idx]);
        inorder(T, 2*idx+1);
    }
}

// 후위 순회
void postorder(int T[], int idx){

    if( T[idx] != 0 ){
        postorder(T, 2*idx);
        postorder(T, 2*idx+1);
        printf("%d ", T[idx]);
    }
}

int main(void){
    int array[] = {0,1,2,3,4,5,6,0,0,7,8,0,0,9,0,0};

    printf("preorder: ");
    preorder(array, 1);
    printf("\ninorder: ");
    inorder(array, 1);
    printf("\npostorder: ");
    postorder(array, 1);

    return 0;
} 