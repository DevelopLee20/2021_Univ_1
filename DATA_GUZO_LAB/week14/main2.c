#include <stdio.h>
#include <stdlib.h>
#define Tree_Size 8

typedef struct Treenode{
    int data;
    struct Treenode *left; 
    struct Treenode *right; 
} TreeNode;

TreeNode* get_node(int data){

    // 노드 동적 생성
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data; // data 입력
    node->left = NULL;
    node->right = NULL;

    return node; // 생성된 노드 반환
}

int Make_Tree(TreeNode *Tree, int T[], int idx){

    if(2*idx >= Tree_Size){ // 트리 사이즈만큼 이진 트리를 만든다.
        return 0;
    }

    Tree->left = get_node(T[2*idx]);    // 왼쪽의 동적 노드 생성
    Tree->right = get_node(T[2*idx+1]); // 오른쪽의 동적 노드 생성
    Make_Tree(Tree->left, T, 2*idx);    // 왼쪽 자식 노드로 이동
    Make_Tree(Tree->right, T, 2*idx+1); // 오른쪽 자식 노드로 이동

}

TreeNode* cons_dir(){
    
    // 트리의 배열 선언
    int T[Tree_Size] = {0,0,50,100,0,0,200,500};

    TreeNode *Tree = get_node(T[1]); // 맨 위의 노드 생성
    TreeNode *tree = Tree;           // 트리 노드 생성
    
    Make_Tree(tree, T, 1);           // 트리 노드를 생성하는 함수

    return Tree;                     // 만든 트리를 반환
}

int calc_dir(TreeNode *Tree){
    // 트리의 각 노드의 끝까지 반복 , 왼쪽, 오른쪽 자식 노드의 data와 자신의 data를 더하고 반환한다.
    if(Tree != 0){  
        return calc_dir(Tree->left) + calc_dir(Tree->right) + Tree->data;
    }
}

int main(void){

    TreeNode *T;
    
    T = cons_dir();
    printf("calc_dir: %d\n", calc_dir(T));

    return 0;
}