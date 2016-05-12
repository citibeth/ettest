#include <everytrace.h>
#include <stdio.h>
#include <string.h>


void main4(char *exit_type, int yp)
{
    printf("xxx Exit type %s\n", exit_type);
    if (strcmp(exit_type, "seg") == 0) {
        int *p = NULL;
        *p = 17;
    } else if (strcmp(exit_type, "et") == 0) {
        everytrace_exit(17);
    }
}

void main3(char *exit_type, int x)
    { main4(exit_type, x*x); }

void main2(char *exit_type, int x)
    { main3(exit_type, x+x*43); }

void main1(char *exit_type)
    { main2(exit_type, 17); }
