#include <iostream>
#include <vector>

using namespace std ;

int main() {
    
    int n, m ;
    cin >> n >> m ;
    vector< int > a(n), b(m) ;

    for ( auto i = 0 ; i < n ; ++i )
        cin >> a[i] ;
    for ( auto i = 0 ; i < m ; ++i )
        cin >> b[i] ; 

    for ( auto i = 1 ; i < m ; ++i ) {
        cout << n-1 << ' ' << i << endl ;
    }
    for ( auto i = 0 ; i < n ; ++i ) {
        cout << i << ' ' << 0 << endl ;
    }

}