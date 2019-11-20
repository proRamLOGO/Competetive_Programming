#include <iostream>
#include <vector>

using namespace std ;

int main() {

    int n, i;
    cin >> n ;
    vector< int > v(n) ;

    for ( i = 0 ; i < n ; ++i )
        cin >> v[i] ;
    
    for ( i = 1 ; i < n ; ++i ) {
        if ( v[i] < v[i-1] ) 
            break ; 
    }

    if ( i == n && v[n-2] > v[n-1] ) {
        cout << n-1 << endl ;
        return 0 ;
    }
    else if ( i == n ) {
        cout << 0 << endl ;
        return 0 ;
    }
    else 
        cout << i << endl ;

}