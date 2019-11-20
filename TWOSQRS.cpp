#include <iostream>
#include <vector>   

using namespace std ;

long int main() {

    long int t ;
    cin >> t ;

    vector< bool > squares(10000000001) ;

    for ( auto i = 0 ; i <= 100000 ; ++i ) squares[i*i] = 1 ;

    while ( t-- ) {

        bool flag = 0 ; 
        long long int n ; 
        cin >> n ; 

        for ( auto i = 1 ; i <= n ; ++i ) {
            if( squares[i] && squares[n-i] ) {
                cout << "Yes\n" ;
                flag = 1 ;
                break ;
            }
        }

        if ( !flag ) cout << "No\n" ;

    }

}