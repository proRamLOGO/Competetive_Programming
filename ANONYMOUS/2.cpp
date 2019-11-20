#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {

    int n ;
    cin >> n ;
    vector< int > v(n) ;

    for( auto i = 0 ; i < n ; ++i ) 
        cin >> v[i] ;

    int m = INT_MIN ;

    for ( auto i = 0 ; i < n-1 ; ++i ) {

        int j = i+1 ;
        cout << v[i] << ' ' <<  max_element( v.begin(), v.end() )  << endl ;
        //( res > m ) ? m = res : 1 ;  

    }

    cout << m << endl ;


}