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

    int t ;
    cin >> t ;

    while( t-- ) {
        
        int n, k ;
        cin >> n >> k;
        vll v(n) ;
        for ( int i = 0 ; i < n ; ++i ) cin >> v[i] ;

        bool res = true ;

        for ( int i = 0 ; i < n ; ++i ) {
            ll pl = v[i]-i-1 ;
            if ( pl < 0 ) pl *= -1;

            if ( pl%k != 0 ) {
                res = false ;
                break;
            }
        }

        if (res)
            cout << "yes" << endl ;
        else
            cout << "no" << endl ;

    }

    return 0 ;

}
