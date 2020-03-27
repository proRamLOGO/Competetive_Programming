#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t=1 ;
    // cin >> t ;
    while( t-- ) {
        
        ulli n, nn;
        cin >> n ;
        nn=n ;
        // if ( n==1 ) {
        //     cout << "1\n0" << endl ;
        //     continue ;
        // }

        ulli ans = 1 ;
        int cnt=0 ;
        for ( ulli i = 2 ; cnt < 2 and i*i <= n ; ++i ) {
            if ( ans==1 and n%i == 0 )
                ans *= i ;
            while( n%i == 0 ) {
                n /= i, ++cnt ;
            }
        }

        if ( n > 1 )
            ++cnt ;

        if ( ans == 1 ) ans=0 ;
        else ans *= (nn/ans) ;

        if ( cnt == 2 ) {
            cout << 2 << endl ;
        } else {
            cout << 1 << endl << ans << endl ;
        }

    }

    return 0 ;

}
