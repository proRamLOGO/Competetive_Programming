#include <iostream>
#include <vector> 

using namespace std ;

int main() {

    int n;
    cin >> n ;

    vector<int> v(n) ;

    for ( auto i = 0 ; i < n ; ++i )    
        cin >> v[i] ;
        
    int count = 0, it = -1 ;

    for ( auto i = 0 ; i < n ; ++i ) {

        if ( v[i]==0 ) {
            if ( count==0 ) it = i ;
            ++count ;
        }
        else if ( it != -1) {
            v[it] = v[i] ;
            ++it ;
        }

    }

    for ( auto i = 0 ; i < count ; ++i ) 
        v[n-1-i] = 0 ;

    for ( auto i = 0 ; i < n ; ++i )    
        cout << v[i] << ' ' ;

    cout << endl ;

}