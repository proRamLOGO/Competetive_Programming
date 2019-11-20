#include <iostream>
#include <bits/stdc++.h>
#define llui long long unsigned int
#define ui unsigned int
using namespace std ;

int min( long long int a, long long int b ) {
    if ( a < b ) 
        return a ;
    return b ;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt","w",stdout) ;    
    #endif

    int t ;
    cin >> t ;

    while ( t-- ) {
 
        ui n, k ;
        cin >> n >> k ;
        
        vector< vector< llui > > v( k ,x) ;

        int r=0, c=0 ;

        for ( int i = 0 ; i < n ; ++i ) {
            
            cin >> v[i%k][i/k] ;
        }

        for ( auto i : v ) {
            for ( auto j : i ) {
                cout << j << ' ' ;
            }
            cout << endl ;
        }
        
    }
}