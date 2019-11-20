#include <stdio.h>

void test( int arr[] ) {
    for ( int i = 0 ; arr[i] != NULL ; ++i )
        arr[i] += i ;
}

void test2( int **arr , int n ) {
    for ( auto i = 0 ; i < n ; ++i ) {
        for ( auto j = 0 ; j < n ; ++j )
            printf ( "%d ", arr[i][j]  ) ;
            //printf ( "%d ", *((arr+i*3)+j)  ) ;
        printf("\n") ;  
    }
}

void main() {
    
    if (0) {
        int a[10] = { 1, 'a', 3, 4, 5 } ;
        char str[] = { 67, 'h', 'u', 'b', 'h', '\n','b', 101, 'n','s', 'a', 'l'  } ;

        printf("%s",str) ;

        test( a ) ;

        for ( int i = 0 ; a[i] != NULL ; ++i )
            printf( "\n%d ",a[i] ) ;
    }

    int n ;
    scanf("%d",&n) ;
    int arr[n][n] ;

    for ( int i = 0 ; i < n ; ++i ) {
        for ( auto j = 0 ; j < n ; ++j ) 
            scanf("%d",&arr[i][j]) ;
    }

    test2(arr,n) ;

}