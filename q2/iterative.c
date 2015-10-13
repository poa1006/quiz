/* FIXME: Implement! */
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 32

char smallest_character(char str[],char c )
{

    int l =0, r = strlen(str)-1;
    char res = str[0];
    while(l <=r ) {
        int m = l + (r-l)/2;
        if (str[m]>c) {
            res = str[m];
            r = m-1;
        } else
            l = m+1;
    }
    return res;
}

int main()
{
    FILE *fp;
    char line[MAX_LINE_SIZE],str[MAX_LINE_SIZE];
    int i,che=0;

    fp = fopen("data.txt","r");

    while (fgets(line, sizeof(line), fp)) {
        while (line[i] != '\0')
            i++;
        line[i - 1] = '\0';

        if(che%2==0)
            strcpy(str,line);
        else
            printf("%c\n", smallest_character(str,line[0]));

        i = 0,che++;
    }

    fclose(fp);
    return 0;
}
