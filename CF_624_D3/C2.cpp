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
 
typedef long long ll;
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

    long int n ;
    cin >> n ;

    vector< ll > v(n) ;
    for ( int i = 0 ; i < n ; ++i ) {
        cin >> v[i] ;
    }

    int mp = 0 ;

    for ( int i = 1 ; i < n ; ++i ) {
        if ( v[mp] < v[i] ) 
            mp = i ;
    }

    for ( int i = mp-1 ; i > -1 ; --i ) {
        v[i] = min(v[i],v[i+1]) ;
    }

    for ( int i = mp+1 ; i < n ; ++i ) {
        v[i] = min(v[i],v[i-1]) ;
    }

    for ( auto i : v )
        cout << i << ' ' ;
    
    cout << endl ;

    return 0 ;
    
}