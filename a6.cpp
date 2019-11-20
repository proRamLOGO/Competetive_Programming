#include <iostream>

using namespace std ;

int main() {

    int n ;
    cin >> n ;

    int hi = n, lo = 1, mid, ans ;

    while ( hi >= lo ) {

        mid = (hi+lo) / 2 ;

        if ( mid*mid <= n ) {
            ans = mid ;
            lo = mid+1 ;
        } 
        else 
            hi = mid-1 ;

    }

    float l = ans, r= ans+1, a ;

    for ( auto i = 0 ; i < 100 ; ++i ) {

        a = (l+r) / 2.0 ;

        if ( a*a < n )
            l = a ;
        else 
            r = a ;

    }

    cout << a ;

}