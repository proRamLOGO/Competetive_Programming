#include <iostream>

using namespace std ;

int pow( int n, int x ) {

    static int call = 1 ;

    if ( x==0 ) return 1 ;

    int res = pow(n,x/2 ) ;
    if ( x%2 ) 
        return n * res * res ;
    else 
        return res * res ;

}

int main() {

    int n,x ;
    cin >> n >> x ;
    cout << pow(n,x) << endl ;


}