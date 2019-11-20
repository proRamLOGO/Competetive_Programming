#include <bits/stdc++.h>
#define llui long long unsigned int
#define M 1000000007

using namespace std ;

llui fastpow( llui n, llui p ) {
    
    if ( p==0 ) 
        return 1 ;

    llui fp = fastpow( (n*n)%M, p/2 )%M ;
    
    if ( p%2==1 ) 
        return (n*fastpow( (n*n)%M, p/2 ))%M ;
    
    return (fastpow( (n*n)%M, p/2 ))%M ;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen("output.txt", "w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while ( t-- ) {
        llui n ;
        cin >> n  ;

        llui ans = 1 ;
        for ( llui i = 2 ; i <= n ; ++i ) 
            ans = ( ans%M * fastpow(i,n-i+1)%M ) % M ;
        
        cout << ans << endl ;

    }
}