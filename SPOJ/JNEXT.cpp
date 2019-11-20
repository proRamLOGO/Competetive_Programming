/*--------------------------------------------
https://www.spoj.com/problems/JNEXT/
--------------------------------------------*/


#include <iostream>
#include <vector>
#include <algorithm>

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
        
        for ( auto i = n-1 ; i > 0 ; --i ) {
            if ( v[i-1] <= v[i] ) {
                v[i-1] += v[i] ;
                v[i] = v[i-1]-v[i] ;
                v[i-1] -= v[i] ;
                sort(v.begin()+i,v.end()) ;
                break ;
            }
        }

        for ( auto i : v ) 
            cout << i ;

    }
    cout << endl ;

}