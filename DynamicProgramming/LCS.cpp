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
        
        string s1, s2 ;
        cin >> s1 >> s2 ;
        vvll dp(len(s1)+1, vll(len(s2)+2,0) ) ;

        for ( int i = 1 ; i <= len(s1) ; ++i ) 
            for ( int j = 1 ; j <= len(s2) ; ++j ) 
                if ( s1[i]==s2[j] ) 
                    dp[i][j] = 1+dp[i-1][j-1] ;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
            
        cout << dp[len(s1)][len(s2)] << endl ;

    }

    return 0 ;

}