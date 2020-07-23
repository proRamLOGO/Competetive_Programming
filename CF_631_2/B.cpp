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
        
        int n, m=0 ;
        cin >> n ;
        vector<int> v(n) ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;

            if ( v[m] <= v[i] )
                m = i ;
        }

        int sn = (m*(m+1)) / 2 ; 

        if( m >= v[m] ) {
            int sa = 0, i ;
            for ( i = n-1 ; sn > sa and i >= 0 ; --i ) {
                sa += v[i] ;
            }
            if ( i==-1 )
                cout << 0 << endl ;
            else 
                cout << "1" << endl << i+1 << ' ' << n-i-1 << endl ;
            continue ;
        }

        int b1 = -1, b2 = -1 ;

        int sa= 0;
        for ( int i = 0 ; i < n ; ++i ) {
            sa += v[i] ;
            if ( sa == sn ) {
                b1 = i+1 ;
                break ;
            }
        }

        sa= 0;
        for ( int i = n-1 ; i >= 0 ; --i ) {
            sa += v[i] ;
            if ( sa == sn ) {
                b2 = i+1 ;
                break ;
            }
        }

        if ( b1 != -1 ) {
            if ( b2 != -1 ) {
                cout << 2 << endl << b1 << ' ' << n-b1 << endl << b2-1 << ' ' << n-b2+1 << endl ;
            }
            else {
                cout << 1 << endl << b1 << ' ' << n-b1 << endl ;
            }
        }
        else {
            cout << 0 << endl ;
        }

    }	
    
	return 0;
}
