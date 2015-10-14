/* FIXME: Implement! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recursive.h"

TreeNode *node_initialize(TreeNode *root,int num[],int index,int size)
{
    if(index <size) {
        if(num[index]==0)
            return NULL;
        else {
            root = malloc(sizeof(TreeNode));
            root ->value = num[index];
            root->left  = node_initialize(root ->left, num,index*2+1,size);
            root->right = node_initialize(root ->right, num,index*2+2,size);
            return root;
        }
    } else
        return NULL;
}

void print_btree(TreeNode *root)
{

    if(root) {
        printf("%d\n",root->value);
        //print_btree(root->left);
        print_btree(root->right);
    }
}

TreeNode *flat(TreeNode *root)
{
    if(root==NULL)
        return NULL;
    if(root->left) {
        TreeNode *pre = root->left;
        while(pre->right!=NULL)
            pre = pre->right;

        pre-> right = root -> right;
        root ->right = root -> left;
        root -> left = NULL;
    }
    if(root->right)
        root->right = flat(root->right);

    return root;
}

void flatten(TreeNode* root)
{
    flat(root);
}
/*
int main()
{
    int num[]= {1,2,5,3,4,0,6};
    TreeNode *root=NULL;
    int size=(int)(sizeof(num)/sizeof(num[0]));

    root=node_initialize(root,num,0,size);

    printf("before flatten:\n");
    print_btree(root);

    flatten(root);
    printf("after flatten :\n");
    print_btree(root);

    return 0;
}*/
