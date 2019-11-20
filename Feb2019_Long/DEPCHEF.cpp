#include <iostream>
#include <vector>

using namespace std ;

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        int n ;
        cin >> n ;

        vector< int > a(n), d(n) ;

        for ( auto i = 0 ; i < n ; ++i ) 
            cin >> a[i] ;
        for ( auto i = 0 ; i < n ; ++i ) 
            cin >> d[i] ;

        int res = INT_MIN ;

        for ( auto i = 0 ; i < n ; ++i ) {

            if ( i==0 && (a[n-1] + a[1]) < d[0] ) {
                if ( d[i] > res )
                    res = d[i] ;
            }
            if ( a[i-1] + a[ (i+1)%n ] < d[i] && i > 0) {
                if ( d[i] > res )
                    res = d[i] ;
            }

        }

        if ( res == INT_MIN )
            res = -1 ;

        cout << res << endl ;

    }

}