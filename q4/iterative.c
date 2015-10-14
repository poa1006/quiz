/* FIXME: Implement! */
#include <stdio.h>

#define MAX_ARRAY_SIZE 32

int maxSubArray(int A[], int n){
 int cur_max=0;
 int max = A[0];
 
 for(int i=0;i<n;i++)
 {
     
     if(cur_max>0)
         cur_max+=A[i];
     else    
        cur_max=A[i];
     
        max = max > cur_max? max : cur_max;
        
 }
    return max;


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
