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
  
typedef unsigned long long int ull;
typedef vector<ull> vll;

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
        
        long int n ;
        ull x ;
        cin >> n >> x ;
        vll v(n), sum(n) ;
        for ( long int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
        }
        sort( allv(v) ) ;

        if ( v[n-1] < x ) {
            cout << 0 << endl ;
            continue ;
        }

        sum[n-1] = v[n-1] ;
        long int ans = 1 ;

        for ( long int i = n-2 ; i > -1 ; --i ) {
            sum[i] = sum[i+1]+v[i] ;
            if ( sum[i]/(n-i) < x )
                break ;
            ++ans ;
        }

        cout << ans << endl ;

    }	
    
	return 0;
}
