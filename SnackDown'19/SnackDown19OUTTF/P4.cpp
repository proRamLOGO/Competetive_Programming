#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t ;
    while( t-- ) {

        long long int n ;
        bool flag = 0;
        cin >> n;
        vector<long long int> a(n),b(n) ;
        //vector< vector<int> > subs;
        for ( auto i = 0 ; i < n ; ++i ) cin >> a[i] ; 
        for ( auto i = 0 ; i < n ; ++i ) cin >> b[i] ; 
        else if ( a == b ) {
            cout << "TAK\n" ;
        }
        else {

            for ( auto i = 0 ; i < n-2 ; ++i ) {
                if( a[i] > b[i] ) {
                    flag = 1 ;
                    break ;
                }

                long long int diff = b[i] - a[i] ;
                a[i] = b[i] ;
                a[i+1] += diff ;
                a[i+2] += diff ;

            }
            if( flag ) { cout << "NIE\n" ; continue ; }
            cout <<"TAK\n" ;
            
        }

    }

}