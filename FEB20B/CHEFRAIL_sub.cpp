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
typedef long l;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<l> vl;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

vl spf(100001); 

void __init__seive() { 
    spf[1] = 1l; 
    for ( l i = 2 ; i <= 100000 ; ++i ) {
        if ( (i&1) )
            spf[i] = i ; 
        else 
            spf[i] = 2 ;
    }
  
    for ( l i = 3 ; i*i <= 100000 ; ++i ) { 
        if (spf[i] == i) { 
            for (l j=i*i ; j <= 100000 ; j+=i ) {
                if (spf[j]==j) 
                    spf[j] = i; 
            }
        } 
    } 
} 
  
vl getFactorization(l num) { 
    vl pfactors; 
    while (num != 1) { 
        pfactors.pb(spf[num]); 
        num = num / spf[num]; 
    } 
    return pfactors; 
} 

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    __init__seive() ;
    // __init_fact() ;

    int t ;
    cin >> t ;
    t = 0 ;
    while ( t--!=0 ) {

        // Inputs and prep
        ll n, m ;
        cin >> n >> m ;
        bool zx = false, zy = false ;
        vector<ll> x(n), y(m) ;
        unordered_map<ll,bool> xpres, ypres ;
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
        ll ans = 0 ;

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

        for ( ll i = 0 ; i < n && zy ; ++i ) {
            ll X = x[i]*x[i] ;
            for ( ll j = 0 ; j < m && y[j] < 0 ; ++j ) {
                ll a = -1*y[j] ;
                ll b = X/a ;                
                if ( a*b == X ) {
                    if ( ypres[b] ) 
                        ++ans ;
                }
            }
        }

        // Second w.r.t. Y Axis

        for ( ll i = 0 ; i < m && zx ; ++i ) {
            ll Y = y[i]*y[i] ;
            for ( ll j = 0 ; j < n && x[j] < 0 ; ++j ) {
                ll a = -1*x[j] ;
                ll b = Y/a ;                
                if ( a*b == Y ) {
                    if ( xpres[b] ) 
                        ++ans ;
                }
            }
        }

        // Including Right Traingles ANGLED AT ORIGIN
        if ( xpres[0] and ypres[0] )
            ans += (n-1)*(m-1) ;
        else if ( xpres[0] ) 
            ans += (n-1)*(m) ;
        else if ( ypres[0] ) 
            ans += (n)*(m-1) ;

        cout << ans << endl ;

    }
    
    return 0 ;

}