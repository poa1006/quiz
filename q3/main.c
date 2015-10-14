
#include <stdio.h>
#include <stdlib.h>
#include IMPL

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
}

