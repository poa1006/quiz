/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>

void Fish_Yated_shuffle(int arr[],int n)
{
    int i,j,tmp;
    for(i=n-1; i>0; i--) {
        j= rand()%(i+1);
        tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }
}
int main()
{
    int num[52];

    for(int i=0; i<52; i++)
        num[i]=i+1;

    Fish_Yated_shuffle(num,52);

    printf("After shuffling :\n");
    for(int i=0; i<52; i++)
        printf("%d\n",num[i]);

    return 0;
}
