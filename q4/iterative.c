/* FIXME: Implement! */
#include <stdio.h>
#include "iterative.h"

int maxSubArray(int A[], int n)
{
    int cur_max=0;
    int max = A[0];

    for(int i=0; i<n; i++) {

        if(cur_max>0)
            cur_max+=A[i];
        else
            cur_max=A[i];

        max = max > cur_max? max : cur_max;

    }
    return max;


}

