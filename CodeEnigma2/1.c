#include <stdio.h>

int main(void) {

    int i=0 ;
    while(i-- != 0){
        i = i - i++ ;
        printf("%d",i) ;
    }
    return 0 ;
}