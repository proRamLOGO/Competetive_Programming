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
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

class DS {

public:

    vector< int > v ;
    int n ;

    DS( int n ) {
        this->n = n ;
        v.resize(n) ;
        for ( int i = 0 ; i < n ; ++i ) v[i] = i ;
    }

    bool unionit( int p, int q ) {
        // Make p parent of q.
        v[root(q)] = root(p) ;
        return true ;
    }

    int root( int x ) {

        while ( v[x] != x ) {
            v[x] = v[v[x]] ;
            x = v[x] ;
        }

        return x ;

    }

} ;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n, md = -1  ;
    cin >> n ;

    // profit, deadline, name 
    vector< tuple < int , int, string > > v(n) ;
    for ( int i = 0 ; i < n ; ++i ) {
        string name ;
        int d, p ;
        cin >> name >> d >> p ;
        v[i] = make_tuple(p,d,name) ;
        md = max(md, d ) ;
    }
    cout << md << endl ;
    sort( all(v) ) ;

    DS ds(md+1) ;

    for ( auto i : v ) {

        int ad = ds.root(get<1>(i)) ;
        if ( ad > 0 ) {
            ds.unionit( ad-1, ad ) ;
        }
        cout << get<2>(i) << ' ' ; 

    }

    cout << endl ;

    return 0 ;

}