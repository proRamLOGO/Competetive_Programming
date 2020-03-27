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
typedef unsigned long long int ulli;
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
    cin >> t ;
    while( t-- ) {
        
        int n ;
        cin >> n ;
        vector<int> v(n), ans(n) ;
        for ( int i = 0 ; i < n ; ++i ) 
            cin >> v[i] ;
        
        ans[0] = 1 ;

        int k=1 ;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( v[i] == v[i-1] )
                ans[i] = ans[i-1] ;
            else { 
                if ( ans[i-1]==1 ) {
                    k=2 ; 
                    ans[i] = 2 ;
                }
                else 
                    ans[i] = 1 ;
            }
        }

// 2
// 1 2 1 2 1 2 1 2 1 2 1 2 

        if ( v[0]!=v[n-1] and ans[0]==ans[n-1] ) {
            if ( v[0]==v[1] )
                ans[0]=2 ;
            else { 
                ans[0]=3 ;
                k=3 ;
            }
        }
        
        cout << k << endl ;
        for ( auto i : ans )
            cout << i << ' ' ;
        cout << endl ;
    }

}