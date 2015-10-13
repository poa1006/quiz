/* FIXME: Implement! */
#include <stdio.h>
#include <string.h>


char smallest_character(char str[],char c,int i)
{
    if(str[i]>c)
        return str[i];
    else if(strlen(str)-1==i)
        return str[0];
    else
        return smallest_character(str,c,++i);

}
