#include <stdio.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
    int is_thread;
} TreeNode;

void thread_inorder(TreeNode *t){
    
    TreeNode *p = t;

    while(p->left != NULL)
        p = p->left;
    
    do{
        // 방문
        p = find_successor(p);
        // 중위 후속자 방문
    } while(p != NULL);
}

TreeNode* find_successor(TreeNode *p){

    TreeNode *q = p->right;

    if(q == NULL || p->is_thread == 1)
        return q;
    
    while(q->left != NULL)
        q = q->left;
    
    return q;
}