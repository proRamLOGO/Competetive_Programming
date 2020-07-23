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
typedef unsigned long long ull;
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

    int t ;
    cin >> t ;

    while( t-- ) {
        
        int n ;
        cin >> n ;
        vll v(n), dp(n,0) ;
        for (int i=0 ; i<n ; ++i)
            cin >> v[i] ;
        
        dp[0] = 1 ;
        for ( int i = 1 ; i < n ; ++i ) {
            for ( int j = i-1 ; j >= 0 ; --j ) 
                if ( v[i] > v[j] )
                    dp[i] = max(dp[i],dp[j]) ;
            ++dp[i] ;
        }

        cout << *max_element(all(dp)) << endl ;

    }

    return 0 ;

}