#include <stdio.h>

void main() {

    char c ;
    scanf("%c", &c) ;

    int n = c ;

    if ( n > 64 && n <= 91 )
        printf("UpperCase\n") ;
    else if ( n > 96 && n <= 123 )
        printf("LowerCase\n") ;
    else 
        printf("Invalid Char\n") ;

}