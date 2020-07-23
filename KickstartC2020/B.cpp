// Author: proRam
// Name: Shubh Bansal
// Dated: May 17, 2020
// Question: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    int t ;
    cin >> t ;
    for ( int _ = 0 ; _ < t ; ++_ ) {

        int ans = 0, n, q;
        cin >> n >> q ;
        int *v;
        v = new int[n] ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
        }

        while( q-- ) {

            char c ;
            cin >> c ;

            if ( c=='U' ) {
                int idx, nv ;
                cin >> idx >> nv ;
                v[idx-1] = nv ;
            } else {
                int l,r ;
                cin >> l >> r ;
                int c = 1 ;
                int na = 0 ;
                for ( int i=l-1 ; i < r ; ++i ) {
                    int f = v[i]*c ;
                    if ( c&1^1 ) 
                        f *= -1 ;
                    na += f ;
                    ++c ;
                }
                ans += na ;
            }

        }

        cout << "Case #" << _+1 << ": " << ans << endl;
    }

    return 0 ;   

}
