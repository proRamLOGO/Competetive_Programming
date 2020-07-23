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

        long int n ;
        cin >> n ;
        vector< int > a(n);
        vll b(n) ;
        for ( long int i = 0 ; i < n ; ++i ) {
            cin >> a[i] ;
        }
        for ( long int i = 0 ; i < n ; ++i ) {
            cin >> b[i] ;
        }

        if ( a[0] != b[0] ) {
            cout << "NO" << endl ;
            continue ;
        }

        bool ans = true ;

        bool mo, o ;
        mo = o = false ;

        if ( a[0]==-1 ) mo = true ;
        if ( a[0]==1 ) o = true ;

        for ( long int i = 1 ; i < n ; ++i ) {
            if ( a[i] == 1 ) {
                if ( ( b[i] < 1 and ( !mo ) ) or ( b[i] > 1 and (!o) ) ){
                    ans = false ;
                    break ;
                }
            } else if ( a[i] == 0 ) {
                if ( ( b[i] < 0 and (!mo) ) or ( b[i] > 0 and (!o) ) ) {
                    ans = false ;
                    break ;
                }
            } else if ( a[i] == -1 ) {
                if ( ( b[i] < -1 and (!mo) ) or ( b[i] > -1 and (!o) ) ) {
                    ans = false ;
                    break ;
                }
            }
        
            if ( a[i]==-1 ) mo = true ;
            if ( a[i]==1 ) o = true ;

        }

        if ( ans ) {
            cout << "YES" << endl ;
        } else {
            cout << "NO" << endl ;
        }

    }

    return 0 ;
    
}