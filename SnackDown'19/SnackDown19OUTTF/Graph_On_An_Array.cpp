#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {

    int t;
    cin >> t ;

    vector< int > primes(230,0) ;
    primes[0] = -1;
    primes[1] = 0 ;
    for( auto i = 2 ; i < 230 ; ++i ) {
        if ( primes[i] == 0 ) {
            for ( auto y = i*2 ; y < 51 ; y += i ) primes[y] = -1 ;
        }
    }


    while( t-- ) {

        int n;
        bool flag = 1 ;
        cin >> n;
        vector<int> arr(n) ;
        for( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;
        sort(arr.begin(),arr.end()) ;

        int prime = 2 , ans = 0;

        for ( auto i = 0 ; i < n ; ++i ) {
            if( primes[arr[i]] == 0 ) primes[arr[i]] = 1 ;
        }

        for ( auto i = 0 ; i < n ; ++i ) {

            if( primes[arr[i]] == 0 ) {
                primes[arr[i]] = 1 ;
                if( arr[i] == prime ) {
                    prime++ ;
                    while ( primes[prime] != 0 ) prime++ ;
                }
            }

            if( primes[arr[i]] == -1 ) {
                arr[i] = prime ;
                prime++ ;
                while ( primes[prime] != 0 ) prime++ ;
                ans++ ;
            }


        }

        cout << ans << endl ;
        for ( auto i = 0 ; i < n ; ++i ) cout << arr[i] << " " ;

    }

}