#include <stdio.h>

int main() 
{ 
    printf( "The file is %s\n", __FILE__ ); 
    printf( "The date is %s\n", __DATE__ ); 
    printf( "The time is %s\n", __TIME__ ); 
    printf( "This is line %d\n", __LINE__ ); 
    printf( "This function is %s\n", __func__ ); 
} 