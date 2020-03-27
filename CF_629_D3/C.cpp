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
        string x ;
        cin >> x ;

        char a[n+1], b[n+1] ;

        bool det1 = false ;

        a[0] = b[0] = '1' ;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( x[i] == '1' ) {
                if ( det1 ) {
                    a[i] = '0' ;
                    b[i] = '1' ; 
                }
                else {
                    a[i] = '1' ;
                    b[i] = '0' ; 
                } 
                det1 = true ;
            } else if ( x[i] == '2' ){
                if ( !det1 ) {
                    a[i] = '1' ;
                    b[i] = '1' ; 
                } else {
                    a[i] = '0' ;
                    b[i] = '2' ; 
                }
            } else {
                a[i] = b[i] = '0' ;
            }
        }

        a[n] = b[n] = '\0' ;

        cout << a << endl << b << endl ;


    }

}