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
  
typedef unsigned int ull;
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
        
        int n ;
        cin >> n ;
        vector< int > p(n), c(n) ;
        
        bool ans = true ;
        
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> p[i] >> c[i] ;
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( c[i]>p[i] ) {
                // cout << p[i] <<' '<< c[i] <<endl ;
                ans = false ;
                // cout << "B! " << i << endl ;
                break ;
            }
            
            if ( i!=0 ) {
                if (!(( p[i]>p[i-1] and c[i]>=c[i-1] and p[i]>=c[i] ) or ( p[i]==p[i-1] and c[i]==c[i-1] and p[i]>=c[i] ))) {
                    ans = false ;
                    break ;
                }
            }

        }

        if ( ans )
            cout << "YES" << endl ;
        else 
            cout << "NO" << endl ;




    }	
    
	return 0;
}
