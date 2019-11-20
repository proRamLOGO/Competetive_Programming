/* #include<iostream>

using namespace std;

void check(int *arr,int m,int n){
    cout<<"Working"<<endl;
}

int main(){

    int arr[2][3] = {0};

    check(arr,2,3);
    return 0;
} */
#include <iostream>
using namespace std ;
void test( int arr[] ) {
    for ( int i = 0 ; arr[i] != NULL ; ++i )
        arr[i] += i ;
}

void test2( int (*arr)[] , int n ) {
    for ( auto i = 0 ; i < n ; ++i ) {
        for ( auto j = 0 ; j < n ; ++j )
            cout << arr[i][j] ;
        cout << endl ;
    }
}

int main() {
    
    /* if (0) {
        int a[10] = { 1, 'a', 3, 4, 5 } ;
        char str[] = { 67, 'h', 'u', 'b', 'h', '\n','b', 101, 'n','s', 'a', 'l'  } ;

        cout << str << endl ;

        test( a ) ;

        for ( int i = 0 ; a[i] != NULL ; ++i )
            cout << a[i] << ' ' ;
    } */

    int n ;
    cin >> n ;
    int (*arr)[n] ;

    for ( int i = 0 ; i < n ; ++i ) {
        for ( auto j = 0 ; j < n ; ++j ) 
            cin >> arr[i][j] ;
    }

    test2(arr,n) ;

}