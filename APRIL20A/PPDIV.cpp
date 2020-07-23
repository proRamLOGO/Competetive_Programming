#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define left first
#define right second
#define MOD 1000000007
#define M 998244353
#define MI 748683265
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ulli;
typedef pair<ll, ll> pll;
typedef vector<ulli> vulli;
typedef vector<vulli> vvulli;
typedef vector<pll> vpll;
typedef vector<string> vs;

void pq( queue<int> q ) {
    while (!q.empty()) 
        cout << q.front() << ' ' , q.pop() ;
}

int powers[] = {2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30, 31, 33, 34, 35, 37, 38, 39, 41, 42, 43, 46, 47, 51, 53, 55, 57, 58, 59, 61, 62 } ;

ulli fpow( ulli n, int x ) {

    if ( x==0 ) return (ulli)1 ;

    ulli res = fpow(n,x/2 ) ;
    if ( x%2 ) 
        return (ulli)(n * (res*res) ) ;
    else 
        return (ulli)(res * res) ;

}

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("ppdivDB.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t ;
    cin >> t ;
    ulli maxn = 0 ;
    vulli tests(t) ;
    for ( int i = 0 ; i < t ; ++i ) {

        cin >> tests[i] ;
        maxn = max(maxn,tests[i]) ;

    }

    vulli f(maxn+1,1), F(maxn+1,1) ;
        
    for ( ulli i = 2 ; i <= maxn ; ++i ) {
        
        ulli ans = (ulli)0 ;
        
        for ( int p = 2 ; p < 38 ; ++p ) {
            
            ulli power ;
            for ( ulli base = 2 ; ; ++base ) {
                
                // cout << base << " ki power " << powers[p] << ' ' << p << endl ;

                // try {
                //     power = fpow(base,powers[p]) ;
                // } catch(...) {
                //     break ;
                // }
                power = fpow(base,powers[p]) ;
                if ( power > i )// constraint altered
                    break ;
                cout << "for i = " << i << ' ' <<  base << " ki power " << powers[p] << ' ' << p << ' ' << power ;
                power = power%M ;

                if ( i%power == 0 ) {
                    cout << "added" ;
                    ans = ( ( power%M + ans ) % M );
                }
                power = fpow(base,powers[p]) ;
                cout << endl ;

            }

        }
        f[i] = ( f[i] + ans ) % M ;
        F[i] = ( f[i] + F[i-1] ) % M ;

    }

    cout << endl << endl << "Function f ********************************************************" <<endl << endl ;
    for ( int i = 1 ; i < maxn ; ++i ) {
        cout << i << " : f(" << i << ")  =  " << f[i] << endl ;
    }
    cout << endl << endl << "Function F ********************************************************" <<endl << endl ;
    for ( int i = 1 ; i < maxn ; ++i ) {
        cout << i << " : F(" << i << ")  =  " << F[i] << endl ;
    }

    return 0 ;
    
}