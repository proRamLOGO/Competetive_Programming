#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector< int > arr(n);
    for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;

    vector< int > primes(201,1) ;
    primes[0] = 0 ;
    primes[1] = 0 ;

    for ( auto i = 2 ; i < 201 ; ++i ) {
        if ( primes[i] ) {
            for ( auto y = i+i ; y < 201 ; y+=i ) primes[y] = 0 ;
        }
    }

    vector< int > semi_primes(201,0) ;

    for ( auto i = 2 ; i < 201 ; ++i ) {
        for ( auto y = i+1 ; y < 201 ; ++y ) {
            if ( primes[i] && primes[y] && i*y < 201) semi_primes[i*y] = 1 ;
        }
    }
    bool flag ;
    for ( auto c : arr ) {
        //cout << "-------------------------------------------------------\nCheck for " << c <<endl;
        flag = 0 ;
        for ( auto i = 6 ; i < c ; ++i ) {

            if ( semi_primes[i] ) {
                int x = c - i ;
                //cout << " i = " << i << "  and  x = " << x << "  and i+x = " << i+x << endl ;
                if ( semi_primes[x] ) {
                    cout << "YES\n" ;
                    flag = 1 ;
                    break ;
                }
            }
        }
        if ( !flag ) cout << "NO\n" ;
    }

}