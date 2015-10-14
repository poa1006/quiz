/* FIXME: Implement! */
#include <stdio.h>
#include <limits.h>

#define MAX_ARRAY_SIZE 32
int max_2(int a,int b)
{
    return (a>b)? a:b;
}
int max(int a,int b, int c)
{
    return max_2(max_2(a,b),c);
}
int maxCrossingSum(int A[],int l,int m,int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i=m; i>=l; i--) {
        sum += A[i];
        if(sum>left_sum)
            left_sum=sum;
    }
    sum=0;
    int right_sum = INT_MIN;
    for(int i = m+1; i<=h; i++) {
        sum +=A[i];
        if(sum>right_sum)
            right_sum=sum;
    }

    return left_sum+right_sum;
}

int maxSubArraySum(int A[],int l,int h)
{
    if(l==h)
        return A[l];
    int m =(l+h)/2;

    return max(maxSubArraySum(A, l, m),
               maxSubArraySum(A, m+1, h),
               maxCrossingSum(A, l, m, h));
}
int maxSubArray(int A[], int n)
{
    return maxSubArraySum(A,0,n-1);
}

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
