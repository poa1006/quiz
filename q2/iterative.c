/* FIXME: Implement! */
#include <stdio.h>
#include <string.h>

#include "iterative.h"

char smallest_character(char str[],char c)
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

