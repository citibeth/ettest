#include <everytrace.h>
#include <stdio.h>


extern void main1(char *exit_type);


int main(int argc, char **argv)
{
    everytrace_init();

    main1(argv[1]);
    printf("Exiting normally\n");
}
