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

ulli bs( ulli n ) {

    ulli lo = 1, hi = 100000 ;
    ulli ans = -1 ;
    while ( hi >= lo ) {
        ulli mid = (lo+hi)/ 2 ;
        ulli sum = (mid*(mid+1)) / 2 ;
        // cout << mid <<' '<< sum << endl ;
        if ( sum == n ) {
            return mid ;
        }
        else if ( sum > n ) {
            ans = mid ;
            hi = mid-1 ;
        } else {
            lo = mid+1 ;
        }
    }

    return ans ;

}

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
        
        ulli n ;
        ulli k ;
        cin >> n >> k ;
        // System.out.println(n+"  "+k);
        ulli p1 = bs(k)+1 ;
        ulli p2 = k- (((p1-2)*(p1-1))/2) ;

        // cout << p1 << ' ' << p2 ;

        for ( ulli i = n ; i > 0 ; --i )
            if ( i == p1 || i == p2 ) 
                cout << 'b' ;
            else 
                cout << 'a' ;
        
        cout << endl  ;


    }

}