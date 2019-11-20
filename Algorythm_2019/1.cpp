#include <bits/stdc++.h>

using namespace std ;

bool func( long long unsigned int n, long long unsigned int k ) {

    long long unsigned int sharma=0, singh = 0, N ;
    N = n ;
    while ( n >= k ) {

        sharma += k ;
        n -= k ;
        singh += n/10 ;
        n -= n/10 ;

    }

    sharma += n ;

    cout << "\nFor k = " << k << " Sharma gets " << sharma << " and Singh gets " << singh ;

    //cout 
    if ( sharma < (N/2) ) 
        return false ;
    else 
        return true ;

}
//34
int main() {

    long long unsigned int n, k, hi, lo, ans ; 
    cin >> n ;

    hi = n ;
    lo = 1 ;
    ans = n ;
    while ( hi > lo ) {

        k = (hi+lo) / 2 ;
        cout  << endl << endl << hi << ' ' << lo << ' ' << k ;
        
        if ( func(n,k) ) {
            ans = k ;
            hi = k ;
        }
        else {
            lo = k ;
        }

    }
    cout << func(n,3) ;

    cout << ans << endl ;

}