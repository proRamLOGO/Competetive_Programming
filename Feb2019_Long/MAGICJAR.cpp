#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std ;

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {
        int n ;
        cin >> n ;
        vector< int > v(n) ;
        for ( auto i = 0 ; i < n ; ++i ) 
            cin >> v[i] ;

        sort(v.begin(),v.end()) ;
        vector< int > sum(n) ;
        
        sum[0] = v[0] ;
        for ( auto i = 1 ; i < n ; ++i ) 
            sum[i] = v[i] + sum[i-1] ;

        if ( n == 1 ) 
            cout << v[0] << endl ;
        else{ 
            for ( auto i = n-1 ; i > 0 ; --i ) {
                cout << sum[n-1] - sum[i-1] << '  +  ' <<  sum[i-1] << endl;
                if ( sum[n-1] - sum[i-1] >= sum[i-1] ) {
                    cout << sum[n-1] - sum[i-1] << endl ;
                    break ;
                }
            }
        }

    }

}