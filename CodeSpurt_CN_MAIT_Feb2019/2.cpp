#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int maxele( vector< int > v, int l, int r ) {
  
    int max = INT8_MIN ;
    for ( auto i = l ; i < r ; ++i ) {

        if ( v[i] > max )  
            max = v[i] ;

    }
    return max ;

}

int main() {

    int n ;
    cin >> n ;
    vector< int > v(n) ;

    for( auto i = 0 ; i < n ; ++i ) 
        cin >> v[i] ;

    int m = INT8_MIN ;

    for ( auto i = 0 ; i < n-1 ; ++i ) {

        int j = i+1 ;
        int res = maxele(v , j, n ) - v[i] ;
        
        ( res > m ) ? m = res : 1 ;  
        
    }

    cout << m << endl ;


}