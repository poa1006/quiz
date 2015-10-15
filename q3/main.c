
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include IMPL

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000.0);
}
int main()
{
    int num[]= {1,2,5,3,4,0,6};
    TreeNode *root=NULL;
    int size=(int)(sizeof(num)/sizeof(num[0]));
    struct timespec start, end;
    double cpu_time1;

    root=node_initialize(root,num,0,size);

    printf("before flatten:\n");
    print_btree(root);

    clock_gettime(CLOCK_REALTIME, &start);
    flatten(root);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("after flatten :\n");
    print_btree(root);

    cpu_time1 = diff_in_second(start, end);
    printf("execution time of flatten() : %lf ms\n", cpu_time1);
    return 0;
}

