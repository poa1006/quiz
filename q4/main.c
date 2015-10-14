#include <stdio.h>
#include <stdlib.h>
#include IMPL

#define MAX_ARRAY_SIZE 32

int main()
{
    FILE *fp;
    fp = fopen("data.txt","r");
    int numberArray[MAX_ARRAY_SIZE],n,i=0;

    while(fscanf(fp, "%d,", &n)>0)
        numberArray[i++]=n;

    n = maxSubArray(numberArray,i);
    printf("largest sum = %d\n",n);

    return 0;
}

