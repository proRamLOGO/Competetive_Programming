#include <iostream>

using namespace std; 

int main() {

    int t;
    cin >> t;
    while ( t-- ) {
        
        int n;
        long int k,x;
        bool flag = 0 ;
        cin >> n >> k ;
        for( auto i = 0 ; i < n ; ++i ) {
            cin >> x;
            if( x >= k ) {
                cout << "YES\n" ;
                flag = 1 ;
                break ;
            }
        }
        if( !flag ) cout << "NO\n" ;
    
    }

}