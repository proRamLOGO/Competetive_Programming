#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
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

    int t=1 ;
    // cin >> t ;
    while( t-- ) {
        
        int n;
        cin >> n ;
        string s ;
        cin >> s ;
        
        int freq[10] = { 0 } ;

        for ( auto i : s ) {
            int idx = i-'0' ;
            if ( idx==2 ) {
                // prime
                ++freq[2] ;
            }
            if ( idx==3 ) {
                // prime
                ++freq[3] ;
            }
            if ( idx==4 ) {
                // 4! = 3! . 2! . 2!
                ++freq[3] ;
                freq[2] += 2 ;
            }
            if ( idx==5 ) {
                // prime
                ++freq[5] ;
            }
            if ( idx==6 ) {
                // 6! = 5!.3!
                ++freq[5] ;
                ++freq[3] ;
            }
            if ( idx==7 ) {
                // prime
                ++freq[7] ;
            }
            if ( idx==8 ) {
                // 8! = 7! .2! .2! .2!
                ++freq[7] ;
                freq[2] += 3 ;
            }
            if ( idx==9 ) {
                // 9! = 7! .2! .3! .3!
                ++freq[7] ;
                ++freq[2] ;
                freq[3] += 2 ;
            }
        }

        for ( int i = 7 ; i > 1 ; --i ) {
            if ( freq[i] > 0 ) {
                for ( int j = 0 ; j < freq[i] ; ++j )
                    cout << i ;
            }
        }
        cout << endl ;
        

    }

    return 0 ;

}
