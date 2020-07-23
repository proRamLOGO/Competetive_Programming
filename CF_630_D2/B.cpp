#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007d
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

        int n ;
        cin >> n ;
        vector<int> v(n), colors(n), primes ; ;

        for ( int i = 0 ; i < n ; ++i )
            cin >> v[i] ;


        primes.pb(2)  ;
        primes.pb(3)  ;
        primes.pb(5)  ;
        primes.pb(7)  ;
        primes.pb(11) ;
        primes.pb(13) ;
        primes.pb(17) ;
        primes.pb(19) ;
        primes.pb(23) ;
        primes.pb(29) ;
        primes.pb(31) ;

        vector<bool> used(n,false) ;

        int m = 1 ;

        for ( int i = 0 ; i < 11 ; ++i ) {

            bool u = false ;

            for ( int j = 0 ; j < n ; ++j ) {
            
                if ( v[j]%primes[i] == 0 and !used[j] ) {

                    used[j] = true ;
                    colors[j] = m ;
                    u = true ;
            
                }

            }

            if (u) ++m ;

        }

        for ( int i = 0 ; i < n ; ++i )
            if ( colors[i]==0 )
                colors[i] = m++ ;

        cout << m-1 << endl ;
        for ( auto i : colors )
            cout << i << ' ' ;
        
        cout << endl ;

    }

    return 0 ;
    
}