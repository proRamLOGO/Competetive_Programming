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
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t ;
    cin >> t ;

    while ( t-- ) {

        ll a, b, c, d ;
        ll x, y, x1, y1, x2, y2 ;
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2 ;
        
        // x1 *= -1 ;
        // y1 *= -1 ;
        // x2 += x1 ;
        // y2 += y1 ;
        // x += x1 ;
        // y += y1 ;

        ll v = b-a ;
        ll h = d-c ;

        bool ans = true ;

        if ( ( v < 0 and x+v < x1  ) or ( v > 0 and x+v > x2 ) or ( h < 0 and y+h < y1 ) or ( h > 0 and y+h > y2 ) )
            ans = false ;
        
        if ( v==0 and a!=0 and !( x-1 >= x1 or x+1 <= x2 ) ) {
            ans = false ;
        }
        if ( h==0 and c!=0 and !( y-1 >= y1 or y+1 <= y2 ) ) {
            ans = false ;
        }

        cout << ((ans)?"Yes":"No") << endl ;

    }

    return 0 ;
    
}