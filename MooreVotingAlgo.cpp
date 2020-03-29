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
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
#define g(x) get<x>

using namespace std;
 
typedef unsigned long long ll;
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

    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for ( int i = 0 ; i < n ; ++i ) 
        cin >> v[i] ;

    int idx = 0, cnt = 1;

    for ( int i = 1 ; i < n ; ++i ) {
        cnt += ( v[idx] != v[i] ) ? -1 : 1 ;
            
        if ( cnt==0 ) {
            idx = i ;
            cnt=1;
        }
    }

    cnt = 0 ;
    for ( auto i : v ) {
        if ( i==v[idx] )
            ++cnt ;
        if ( cnt > n/2 )
            break ;
    }

    if ( cnt > n/2 ) {
        cout << v[idx] << endl ;
    } else {
        cout << -1 << endl ;
    }

    return 0 ;

}