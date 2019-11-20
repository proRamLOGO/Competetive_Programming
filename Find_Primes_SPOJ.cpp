#include <iostream>
#include <vector>

using namespace std ;

long int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    long long int t, n ;
    long long int x = 10000001 ;
    vector< long long int > primes( x, 1 );

    primes[0] = 0 ;
    primes[1] = 0 ;

    for ( auto i = 2 ; i < x ; ++i ) {

        if ( primes[i] ) {
            for ( auto y = i+i ; y < x ; y+=i ) primes[y] = 0 ;
        }

    } 

    cin >> t ;

    while ( t-- ) {

        long long int ans = 0;

        cin >> n ;
        vector< long long int > facts(n+1,1) ;

        for ( auto i = n ; i > 0 ; --i ) {

            if ( facts[i] ) {
                for ( auto y = 2 ; y < i ; ++y ) {
                    if ( i%y == 0 )
                        facts[y] = 0 ;
                }
            }

        }

        for ( auto i = 2 ; i <= n ; ++i ) {
            if ( facts[i] && primes[i] ) ans++ ;
        }

        cout << ans << endl ;

    }

}