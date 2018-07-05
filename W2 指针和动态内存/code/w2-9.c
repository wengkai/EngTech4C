#include <stdio.h>
#include <stdarg.h>

void std_vararg_func(const char *fmt, ... ) 
{
    va_list ap;
    va_start(ap, fmt);

    printf("%d\n", va_arg(ap, int));
    printf("%f\n", va_arg(ap, double));
    printf("%s\n", va_arg(ap, char*));

    va_end(ap);
}

int main() 
{
    std_vararg_func("%d %f %s\n", 4, 5.4, "hello world");
}