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

        int n,k ;
        cin >> n >> k ;
        vll v(n) ;
        for ( int i = 0 ; i < n ; ++i ) cin >> v[i] ;
        unordered_map<ll,int> sumfreq ;
        ll me = *min_element(allv(v)) ;
        for ( int i = 0 ; i < n/2 ; ++i) {
            ++sumfreq[ v[i]+v[n-i-1] ] ;
        }
        vpll sfreq ;
        for ( auto i : sumfreq ) {
            sfreq.pb( mp( i.first, i.second ) ) ;
        }
        sort(allv(sfreq)) ;

        ll d = -1 ;
        for ( auto i : sfreq ) {
            ll x = i.second ;
            ll fofx = i.first ;
            if (  )
        }
    

    }

    return 0 ;
    
}