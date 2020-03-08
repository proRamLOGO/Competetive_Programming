#include <bits/stdc++.h>
#define llui long long unsigned int
#define lli long long int

using namespace std ; 

int main() {

    #ifndef ONLINE_JUDGE
        freopen( "input.txt", "r", stdin ) ;
        freopen( "output.txt", "w", stdout ) ;
    #endif

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    int t ;
    cin >> t ;

    while ( t-- ) {

        int n ;
        cin >> n ;
        lli s = INT_MIN, e = INT_MAX ;
        lli x, y ;
        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> x >> y ;
            s = max(s,x) ;
            e = min(e,y) ;
        }
        // cout << s << "  :  "  << e << endl ;
        cout << max((lli)0,(s-e)) << endl ;

    }

    return 0 ;

}