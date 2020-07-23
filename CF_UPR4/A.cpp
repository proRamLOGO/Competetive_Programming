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
#define fori(n) for( auto i = 0; i < n; ++i )
  
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
    
    int n,m,q ;
    cin >> n >> m >> q ;
    string s, t ;
    cin >> s >> t ;

    int li = 0 ;
    vector<int> cnt(n,0) ;
    for ( int i = m-1 ; i < n ; ++i ) {
        int c = 0 ;
        for ( int j = i ; j>=m-1 ; --j ) {
            string a = s.substr(j-m+1,m) ;
            // cout << j << " " << a  ;
            if ( a.compare(t) == 0 ){ ++c ;
                // cout << "  equal" ;
            }
            // cout << endl ;
        }
        cnt[i] = c ;
        // cout <<"c = " << c << endl ;
        // cout << "********************************" << endl ;
    }

    // for ( auto i : cnt )
    //     cout << i << " ";
    // cout << endl;

    while ( q-- ) {

        int l, r ;
        cin >> l >> r ;
        if (l==r) cout << cnt[l-1] << endl ;
        else {
            int ans = cnt[r-1] ;
            if ( l>0 )
                ans -= cnt[l-1] ;
            cout << ans << endl ;
        }
    }

    return 0 ;
    
}