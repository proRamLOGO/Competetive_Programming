#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;

int main() {

    long long int t ;

    cin >> t ;

    while ( t-- ) {

        long long int n, ans = 0 ;

        cin >> n;

        vector< long long int > v(n) ;

        for ( auto i = 0 ; i < n ; ++i ) 
            cin >> v[i] ;

        sort( v.begin(), v.end() );

        for ( auto i = 0 ; i < n ; ++i ) {

            if ( ans >= v[i] )
                ans ++ ;
            else 
                break ; 

        }

        cout << ans << endl ;

        
    }

}