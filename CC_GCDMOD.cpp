#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
#define g(x) get<x>
#define M 1000000007
using namespace std;
 
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef __uint128_t u128;

ll fpow( ll base, ll exp, ll MOD = M ) {

    if (base<2) 
        return base ;

    ll res= 1 ; 
    while ( exp > 0 ) {
        if ( exp&1 ) 
            res = ( base %MOD * (u128)res %MOD ) %MOD ;
    
        exp >>= 1 ;
        base = ( (u128)base %MOD * (u128)base %MOD ) %MOD ;
    }
    return res ;
}

ll gcd( ll a, ll b ) {

    if ( a > b ) 
        return gcd( b, a ) ;
    
    if ( a==0 )
        return b ;

    return gcd( (ll)(b%a), a ) ;

}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t ;
    cin >> t ;
    
    while (t--) {

        ll a, b, n, d  ;
        cin >> a >> b >> n ;
        
        d = a-b ;
        if ( d < 0 )
            d *= -1 ;

        if ( a==b ) {
            ll p = ( fpow(a,n)% M + fpow(a,n) %M )% M  ;
            cout << p << endl ;
            continue;
        }

        ll ap = fpow(a,n,d) ;
        ll bp = fpow(b,n,d) ;

        ap = (ap + bp) %M ;

        cout << gcd(ap,d) << endl ;

    }

    return 0 ;

}