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
typedef vector<ll> vll;

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t ;
    cin >> t ;
    
    while (t--) {
        
        int n, m=0 ;
        cin >> n ;
        vll h(n),d(n), diff(n) ;
        ll td = 0 ;
        
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> h[i] >> d[i] ;
            if (i>0) {
                diff[i] = max(0ll,h[i] - d[i-1]) ;
                td += diff[i] ;
            }
        }
        diff[0] = max(h[0] - d[n-1],0ll) ;
        td += diff[0] ;
        // if ( td<0 ) td *= -1 ;
        int idx = 0 ;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( td - diff[i] + h[i] < td - diff[idx] + h[idx] )
                idx = i ;
        }

        cout << td - diff[idx] + h[idx] << endl ;

        // int ans = h[idx] ;
        
        // for ( int i = 1 ; i < n ; ++i ) {
        //     int idxc = (idx+i)%n ;
        //     int idxp = (idx+i-1)%n ;
        //     ll damage = 0ll ;
        //     if ( h[idxc] > d[idxp] ) {

        //         damage += ( h[idxc] - d[idxp] ) ;
        //     }
        //     // cout <<idxc << ' '<< damage << endl ;

        //     ans += damage ;
        // }

        // cout << ans << endl ;

    }	
    
	return 0;
}
