#include <stdio.h>
#include <string.h>
#include <time.h>
#include IMPL

#define MAX_LINE_SIZE 32

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{
    FILE *fp;
    char line[MAX_LINE_SIZE],str[MAX_LINE_SIZE];
    int i,che=0;
    struct timespec start, end;
    double cpu_time1;

    fp = fopen("data.txt","r");
    clock_gettime(CLOCK_REALTIME, &start);
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
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);
    fclose(fp);

    printf("execution time of smallest_character() : %lf sec\n", cpu_time1);
    return 0;
}
