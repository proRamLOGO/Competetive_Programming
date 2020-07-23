#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first  
#define sc second
#define MOD 1000000007
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t=1 ;
    // cin >> t ;

    while ( t-- ) {

        int n ;
        cin >> n ;
        vector<ll> v(n), pre(n), suf(n) ;

        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
        }
        string s ;
        cin >> s ;
        pre[0] = (s[0]=='B')?v[0]:0 ;
        suf[n-1] = (s[n-1]=='A')?v[n-1]:0 ;
        for ( int i = 1 ; i < n ; ++i ) {
            pre[i] = pre[i-1] + ((s[i]=='B') ? v[i] : 0 ) ;
            suf[n-1-i] = suf[n-i] + ((s[n-1-i]=='A')?v[n-1-i] : 0) ;
        }

        // for ( auto i : pre ) cout << i << ' ' ;
        // cout << endl ;
        // for ( auto i : suf ) cout << i << ' ' ;
        // cout << endl ;cout << endl ;
        
        ll ans = 0 ;
        for ( int i = 0 ; i < n ; ++i ) {
            // cout << pre[i-1] << ' ' << suf[i+1] << ' ' << pre[i-1]+suf[i+1] << endl ;
            ll a = 0, b = 0 ;
            a = pre[i] ;
            if (i<n-1) b = suf[i+1] ;
            // cout << a << ' ' << b << ' ' << a+b << endl ;
            ans = max(ans,a+b) ;
        }
        cout << max(ans,suf[0]) << endl ; 
    }

    return 0 ;
    
}