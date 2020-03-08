#include <bits/stdc++.h> 
#define allv(v) v.begin(), v.end()
 
using namespace std;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    // __init_nCr()  ;
    // __init_fact() ;

    uint8_t t ;
    cin >> t ;
    t -= '0' ;
    
    while ( t--!=0 ) {

        // Inputs
        uint16_t n ;
        cin >> n ;
        vector<uint32_t> a(n), b(n) ;
        for ( int i = 0 ; i < n ; ++i ) cin >> a[i] ; 
        for ( int i = 0 ; i < n ; ++i ) cin >> b[i] ; 

        //Solution
        sort(allv(a)) ;
        sort(allv(b)) ;

        uint64_t ans = 0 ;

        for ( int i = 0 ; i < n ; ++i )
            ans += min(a[i],b[i]) ;

        cout << ans << endl ;

    }
    
    return 0 ;

}