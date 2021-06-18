#include <stdio.h>
#include <stdlib.h>
#define Tree_Size 8
#define max(a,b) (a > b ? a : b)

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

TreeNode* left_node_count(TreeNode *T){
    
}

TreeNode* cons_dir(){
    
    // 트리의 배열 선언
    int T[Tree_Size] = {0,0,50,100,-1,-1,200,500};

    TreeNode *Tree = get_node(T[1]); // 맨 위의 노드 생성
    TreeNode *tree = Tree;           // 트리 노드 생성
    
    Make_Tree(tree, T, 1);           // 트리 노드를 생성하는 함수

    return Tree;                     // 만든 트리를 반환
}

// 트리에 포함된 노드의 개수
int get_node_count(TreeNode *T){
    if(T == NULL)
        return 0;
    return 1 + get_node_count(T->left) + get_node_count(T->right);
}

// 잎노드의 개수
int get_leaf_count(TreeNode *T){
    if(T == NULL || T->data < 0)
        return 0;

    else if(T->left == NULL && T->right == NULL || T->left->data < 0 && T->right->data < 0){
        return 1;
    }

    else{
        return get_leaf_count(T->left) + get_leaf_count(T->right);
    }
}

// 트리의 높이
int get_height(TreeNode *T){
    if(T == NULL)
        return 0;

    return 1 + max(get_height(T->left), get_height(T->right));
}

int main(void){

    TreeNode *T;
    
    T = cons_dir();

    printf("%d\n", get_node_count(T));
    printf("%d\n", get_leaf_count(T));
    printf("%d\n", get_height(T));

    return 0;
}