// Author: proRam
// Name: Shubh Bansal
// Dated: 
// Question: https://www.spoj.com/problems/EASYMATH/

#include <bits/stdc++.h>
using namespace std;

//Binary Functions
#define PARITY __builtin_parity
#define STBTS __builtin_popcount
#define CLRLZ __builtin_clz
#define CLRTZ __builtin_ctz
#define PARITY1 __builtin_parityl
#define STBTS1 __builtin_popcountl
#define CLRLZ1 __builtin_clzl
#define CLRTZ1 __builtin_ctzl
#define PARITY2 __builtin_parityll
#define STBTS2 __builtin_popcountll
#define CLRLZ2 __builtin_clzll
#define CLRTZ2 __builtin_ctzll
#define IS2PWR(x) ( x && !(x&(x-1)) )
// Case changers
#define UPPR(c) ((char)(c&'_'))
#define LOWR(c) ((char)(c|' '))

#define lcm(a,b) (a*b/__gcd(a,b))

using ll = long long ;
using ull = unsigned long long ;
using pll = pair<ll, ll> ;
using vll = vector<ll> ;
using vpll = vector<pll> ;
using vvll = vector<vll> ;
using vs = vector<string> ;

int32_t main(int argc, char** argv) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    int t;
    cin >> t ;
    
    while( t-- ) {

        int n,m,a,d;
        cin >> n >> m >> a >> d ;

        vector<int> primes = { a, a+d, a+d*2, a+d*3, a+d*4 } ;
        // print(primes) ;NEWL;
        int ans = 0 ;
        --n;
        for ( int i = 1 ; i < (1<<(primes.size())) ; ++i ) {
            int pro = 1 ;
            for ( int j = 0 ; j < primes.size() ; ++j )
                if ( (i>>j)&1 ) 
                    pro = lcm(pro,primes[j]) ;

            int div = m/pro - n/pro ;
            // DBG(i), DBG(pro);
            // NEWL;
            if ( STBTS(i)&1 ) {
                ans += div ;
            } else {
                ans -= div ;
            }
        }

        cout << m-n-ans << '\n' ;
        
    }

    cout << endl ;

    return 0 ;   

}
