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

    if(2*idx >= Tree_Size){
        return 0;
    }

    Tree->left = get_node(T[2*idx]);
    Tree->right = get_node(T[2*idx+1]);
    Make_Tree(Tree->left, T, 2*idx);
    Make_Tree(Tree->right, T, 2*idx+1);

}

TreeNode* cons_dir(){

    int T[Tree_Size] = {0,0,50,100,0,0,200,500};

    TreeNode *Tree = get_node(T[1]);
    TreeNode *tree = Tree;
    
    Make_Tree(tree, T, 1);

    return Tree;
}

int calc_dir(TreeNode *Tree){
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