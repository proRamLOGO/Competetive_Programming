/*--------------------------------------------
https://www.spoj.com/problems/JNEXT/
--------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
        freopen( "input.txt","r",stdin ) ;
        freopen( "output.txt","w",stdout ) ; 
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while ( t-- ) {

        long long int n ;
        cin >> n ;
        vector< int > v(n) ;

        bool possible = false ;
        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            if ( i > 0 && v[i-1] <= v[i] )
                possible = true ;
        }
        
        if ( !possible ) {
            cout << -1 << endl ;
            continue ;
        }

        int i=n,j=n ;
        for ( i = n-1 ; i > 0 && v[i-1] >= v[i] ; --i ) 1;
        --i ;

        for ( j = i+1 ; j < n && v[i] < v[j] ; ++j ) 1;
        swap(v[i],v[j-1]) ;

        ++i ;
        sort( v.begin()+i, v.end() ) ;

        for ( auto k : v ) 
            cout << k ;
			
        cout << endl ;
        
    }

}