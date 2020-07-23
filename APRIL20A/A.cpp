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
 
typedef long long unsigned int ulli ;

vector<ulli> spf(1e7,1) ;

void __init__spf() {

    for ( ulli i = 2 ; i < 1e7 ; ++i ) {
        if ( spf[i] == 1 ) {
            spf[i] = i ;
            for ( ulli j = i*i ; j < 1e7 ; j += i ) {
                if ( spf[j]==1 )
                    spf[j] = i ;
            }
        }
    }

}

int smpf( ulli n ) {
    for ( int i = 2 ; i*i <= n ; ++i )
        if ( n%i == 0 )
            return i ;
    return n ;
}

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    __init__spf() ;

    // for ( int i = 0 ; i < 102 ; ++i )
    //     cout << spf[i] << ' ' ;
    // cout << endl ;

    int t ;
    cin >> t ;
    
    while (t--) {
        
        ulli x, k, z=1 ;
        cin >> x >> k ;
        
        int cnt = 0 ;

        while ( x > 1 ) {

            int s ;
            if ( x >= 1e7 ) {
                s = smpf(x) ;
            } else {
                s = spf[x] ;
            }

            x /= s ;
            ++cnt ;

        }

        cout << (cnt>=k) << endl ;

    }	
    
	return 0;
}
