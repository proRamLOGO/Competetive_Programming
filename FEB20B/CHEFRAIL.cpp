#include <bits/stdc++.h> 
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

    // __init_nCr()  ;
    // __init_fact() ;

    uint8_t t ;
    cin >> t ;
    t -= '0' ;
    
    while ( t--!=0 ) {

        // Inputs and prep
        uint32_t n, m ;
        cin >> n >> m ;
        bool zx = false, zy = false ;
        vector<int32_t> x(n), y(m) ;
        unordered_map<int32_t,bool> xpres, ypres ;
        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> x[i] ; 
            xpres[x[i]] = true ;
        }
        for ( auto i = 0 ; i < m ; ++i ) {
            cin >> y[i] ; 
            ypres[y[i]] = true ;
        }

        sort(allv(x)) ;
        sort(allv(y)) ;

        if ( x[0] < 0 and x[len(x)-1] > 0 ) zx = true ;
        if ( y[0] < 0 and y[len(y)-1] > 0 ) zy = true ;

        // Solution ;
        uint32_t ans = 0 ;

        /* 
        // Derivation 
        X = xi
        a = yj
        b = yk
        (a + b)^2 == 2i^2 + a^2 + b^2 
        => i^2 == a.b 
        OR
        => a == i && b = 0 
        */

        // First w.r.t. X Axis

        for ( uint32_t i = 0 ; i < n && zy ; ++i ) {
            int32_t X = x[i]*x[i] ;
            for ( uint32_t j = 0 ; j < m && y[j] < 0 ; ++j ) {
                int32_t a = -1*y[j] ;
                int32_t b = X/a ;                
                if ( a*b == X ) {
                    if ( ypres[b] ) 
                        ++ans ;
                }
            }
        }

        // Second w.r.t. Y Axis

        for ( uint32_t i = 0 ; i < m && zx ; ++i ) {
            int32_t Y = y[i]*y[i] ;
            for ( uint32_t j = 0 ; j < n && x[j] < 0 ; ++j ) {
                int32_t a = -1*x[j] ;
                int32_t b = Y/a ;                
                if ( a*b == Y ) {
                    if ( xpres[b] ) 
                        ++ans ;
                }
            }
        }

        // Including Right Traingles ANGLED AT ORIGIN
        if ( xpres[0] or ypres[0] )
            ans += n*m ;

        cout << ans << endl ;

    }
    
    return 0 ;

}