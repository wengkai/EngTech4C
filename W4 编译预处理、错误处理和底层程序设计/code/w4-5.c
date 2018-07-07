#include <stdio.h>
#include <setjmp.h>

static jmp_buf env;

double divide(double to, double by)
{
    if(by == 0)
        longjmp(env, 1);
    return to / by;
}

int main() 
{
    if (setjmp(env) == 0)
        divide(2, 0);
    else
        printf("Cannot / 0\n");
    printf("done\n");
}