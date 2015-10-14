#ifndef _Q3_H
#define _Q3_H

typedef struct TREE_NODE {
    int value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} TreeNode;

TreeNode *node_initialize(TreeNode *root,int num[],int index,int size);
void print_btree(TreeNode *root);
void flatten(TreeNode* root);

#endif
