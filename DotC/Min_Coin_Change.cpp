#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

long long int minCoinChange( long long int n, vector< long long int > change) {

    if ( n <= 0 )
        return 0 ;
    long long int ans = 100000 ;

    for ( auto i = 0 ; i < change.size() ; ++i ) {
        if( change[i] <= n ) {
            ans = 1 + min( minCoinChange( n-change[i], change ), ans ) ;
        }

    }
    return ans ;

}

long long int main() {

    long long int n, m ;
    cin >> n >> m ;
    vector< long long int > change(m) ;

    for ( auto i = 0 ; i < m ; ++i ) 
        cin >> change[i] ; 

    long long int ans = minCoinChange( n, change ) ;
    cout << ans << endl ;

}