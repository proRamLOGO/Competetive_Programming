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
    
    int t ;
    cin >> t ;

    while ( t-- ) {

        ll n ;
        cin >> n ;

        if ( n%4 != 0 ) { 
            cout << "NO" << endl ;
            continue ;
        }

        vll v ;
        ll sume = 0 ;
        for ( ll i = 2, cnt=0 ; cnt < n/2 ; ++cnt, i+=2 ) {
            v.pb(i) ;
            sume += i ;
        }
        ll sumo = 0 ;
        for ( ll i = 1, cnt = n/2 ; cnt < n-1 ; ++cnt, i+=2 ) {
            v.pb(i) ;
            sumo += i ;
        }
        v.pb( sume-sumo ) ;

        cout << "YES" << endl ; 
        for ( auto i : v )
            cout << i << " " ;
        cout << endl ;
    

    }

    return 0 ;
    
}