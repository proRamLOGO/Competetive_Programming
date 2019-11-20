#include <iostream>
#include <vector>

using namespace std ;

int main() {

    int n ;
    cin >> n ;

    vector< int > v(n) ;

    for ( auto i = 0 ; i < n ; ++i ) 
        cin >> v[i] ;
    
    // to make peak at eve index.

    for ( auto i = 0 ; i < n-1 ; i+=2 ) {

        if ( i == 0 && v[i] < v[i+1] ) {
            v[i+1] += v[i] ; 
            v[i] = v[i+1] - v[i] ;
            v[i+1] -= v[i] ;
            continue ;
        }

       /* if ( v[i-1] > v[i] ) {
            v[i-1] += v[i] ; 
            v[i] = v[i-1] - v[i] ;
            v[i-1] -= v[i] ;
        }
        */
        if ( v[i+1] > v[i] ) {
            v[i+1] += v[i] ; 
            v[i] = v[i+1] - v[i] ;
            v[i+1] -= v[i] ;
        }
    
    }

    for ( auto i : v ) 
        cout << i << ' ' ;
    
    cout << '\n' ;


}
