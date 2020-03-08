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

void generate( int n, string gen , vector<string>& vs ) {

    if ( gen.size() == n ) {
        vs.pb(gen) ;
        return ;
    }
    int i = gen.size() ;
    if ( gen[i-1] != gen[i-2] ) {
        generate( n, gen+"L", vs ) ;
        generate( n, gen+"R", vs ) ;
    } else {
        if ( gen[i-1]=='L' )
            generate( n, gen+"R", vs ) ;
        else 
            generate( n, gen+"L", vs ) ;
    }

}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    // __init_nCr()  ;
    // __init_fact() ;

    int t ;
    cin >> t ;
    
    while ( t--!=0 ) {

        int n ;
        cin >> n ;  
        vector<int> v(n) ;
        for ( auto i = 0 ; i < n ; ++i ) cin >> v[i] ;

        vector<string> vs ;
        generate(n,"LR",vs) ;

        for ( auto i : vs ) {
            if ( valid(n,v,i) ) {
                cout << i << endl ;
                break ;
            }
        }
        // string ans = solve(v,n,i, 0, 0, "", false ) ;

    }
}