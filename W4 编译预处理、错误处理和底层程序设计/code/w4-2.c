#include <stdio.h>

int main()
{
    #if _WIN32
        system("color 0c");
        printf("Win: C Programming\n");
    #elif __linux__
        printf("\033[22;31mLinux: C Programming\n\033[22;30m");
    #else
        printf("C Programming\n");
    #endif
    return 0;
}