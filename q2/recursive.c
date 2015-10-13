/* FIXME: Implement! */
#include <stdio.h>
#include <string.h>



char smallest_character(char str[],char c)
{
    char temp;
    if(strlen(str)==0)
        return 0;
    else if(str[0]>c)
        return str[0];
    else {
        temp = smallest_character(str+1,c);
        if(temp<c)
            return str[0];
        else
            return temp;
    }
    return 0;

}
