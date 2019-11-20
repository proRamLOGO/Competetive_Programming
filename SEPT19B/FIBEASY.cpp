#include <iostream>
#include <vector>
#include <math.h>
#define llui long long unsigned int

using namespace std ;

int _log2( llui n ) {

    int l = 0;
    while( n!=0 ) {
        l++ ;
        n/=2 ;
    }
    return l ;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    vector< short unsigned int > fib(62,1) ;
    fib[0] = 0;
    for ( auto i = 3 ; i < 62 ; ++i ){
        fib[i] = (fib[i-1] + fib[i-2])%10 ;
        //cout << i << ' ' << fib[i] << '\n' ;
    }
    while( t-- ) {
        llui n;
        cin >> n ;
        llui a = 0, d = 2 ;
        int l = 0;
        while( n!=1 ) {
            l++ ;
            n/=2 ;
        }
        //cout << p << " "<< (1<<p) << " " ;
        llui z=1;
        llui p = z<<l ;
        cout << p << " " ;
        p=1 ;
        for ( auto i = 0 ; i < l ; ++i ) {
            p*=2;
            //p%=60;
        }
        cout << p << endl ;
        cout << fib[p - 1]%10 << endl ;
    }
}
