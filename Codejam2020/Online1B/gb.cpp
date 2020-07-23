#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define EB2 1000000000
#define E 2000000000
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

string r1,r2 ;
// 3 : hit ;
// 6 : center ;
// 4 : miss ;
ull *ax=NULL, *ay=NULL ;

ull ts_ltor1( ull lo, ull hi, bool left, ll lvl ) { 

    // leftmost point
    ull mid1, mid2, ans ;
    ans = (left)? EB2 : -EB2 ;

    while (hi >= lo) { 
  
        mid1 = lo + (hi - lo) / 3ll; 
        mid2 = hi - (hi - lo) / 3ll; 
  
        cout << mid1 << " " << lvl << endl ;
        cerr << mid1 << " " << lvl << endl ;
        cin >> r1 ;
        cerr << "                               " << r1 << endl ;

        cout << mid2 << ' ' << lvl << endl ;
        cerr << mid2 << ' ' << lvl << endl ;
        cin >> r2 ;
        cerr << "                               " << r2 << endl ;

        //both miss then inbetween
        if ( r1.size()==4ll and r2.size()==4ll ) {
            lo = mid1+1ll ;
            hi = mid2-2ll ;
        }
        // lies in right
        else if ( r1.size()==3ll ) {
            hi = mid2-1ll ;
            ans = min(ans,mid1) ;
        }
        //lies in left
        else {
            lo = mid1+1ll ;
        }

    } 

    return ans ;
} 


ull ts_ltor2( ull lo, ull hi, bool left, ll lvl  ) { 

    // rightmost point
    ull mid1, mid2, ans ;
    ans = (left)? EB2 : -EB2 ;

    while (hi >= lo) { 
  
        mid1 = lo + (hi - lo) / 3ll; 
        mid2 = hi - (hi - lo) / 3ll; 
  
        cout << mid1 << ' ' << lvl << endl ;
        cerr << mid1 << ' ' << lvl << endl ;
        cin >> r1 ;
        cerr << "                               " << r1 << endl ;

        cout << mid2 << ' ' << lvl << endl ;
        cerr << mid2 << ' ' << lvl << endl ;
        cin >> r2 ;
        cerr << "                               " << r2 << endl ;

        //both miss then inbetween
        if ( r1.size()==4ll and r2.size()==4ll ) {
            lo = mid1+1ll ;
            hi = mid2-2ll ;
        }
        // lies in right
        else if ( r2.size()==3ll ) {
            lo = mid1+1 ;
            ans = max(ans,mid2) ;
        }
        //lies in left
        else {
            hi = mid2-1ll ;
        }

    } 

    return ans ;
} 



ull ts_ttob1( ull lo, ull hi, bool top, ll lvl  ) { 

    // topmost point
    ull mid1, mid2, ans ;
    ans = (top)? -EB2 : EB2 ;

    while (hi >= lo) { 
  
        mid1 = lo + (hi - lo) / 3ll; 
        mid2 = hi - (hi - lo) / 3ll; 
  

        cout << lvl << ' ' << mid1 << endl ;
        cerr << lvl << ' ' << mid1 << endl ;
        cin >> r1 ;
        cerr << "                               " << r1 << endl ;
        cout << lvl << ' ' << mid2 << endl ;
        cerr << lvl << ' ' << mid2 << endl ;
        cin >> r2 ;
        cerr << "                               " << r2 << endl ;

        //both miss then inbetween
        if ( r1.size()==4ll and r2.size()==4ll ) {
            lo = mid1+1ll ;
            hi = mid2-2ll ;
        }
        // lies in top
        else if ( r2.size()==3ll ) {
            lo = mid1+1ll ;
            ans = max(ans,mid2) ;
        }
        //lies down
        else {
            hi = mid2-1ll ;
        }

    } 

    return ans ;
} 


ull ts_ttob2( ull lo, ull hi, bool top, ll lvl  ) { 

    // bottommost point
    ull mid1, mid2, ans ;
    ans = (top)? -EB2 : EB2 ;

    while (hi >= lo) { 
  
        mid1 = lo + (hi - lo) / 3ll; 
        mid2 = hi - (hi - lo) / 3ll; 
  
        cout << lvl << ' ' << mid1 << endl ;
        cerr << lvl << ' ' << mid1 << endl ;
        cin >> r1 ;
        cerr << "                               " << r1 << endl ;
        cout << lvl << ' ' << mid2 << endl ;
        cerr << lvl << ' ' << mid2 << endl ;
        cin >> r2 ;
        cerr << "                               " << r2 << endl ;

        //both miss then inbetween
        if ( r1.size()==4ll and r2.size()==4ll ) {
            lo = mid1+1ll ;
            hi = mid2-2ll ;
        }
        // lies in right
        else if ( r1.size()==3 ) {
            hi = mid2-1ll ;
            ans = min(ans,mid1) ;
        }
        //lies in left
        else {
            lo = mid1+1ll ;
        }

    } 

    return ans ;
} 

int32_t main() {

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin) ;
    // freopen("output.txt", "w", stdout) ;
    // #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL) ; cout.tie(NULL) ;

    int t ;
    cin >> t ;
    ll a,b ;
    cin >> a >> b ;
    cerr << t << ' ' << a << ' ' << b << endl ;
    for ( int T = 1 ; T <= t ; ++T ) {
        
        // pll ul,ur,bl,br ;
        // ul = ur = bl = br = mp(0,0) ;

        ull t,b,l,r ;
        t = ts_ttob1(-EB2,EB2,true,0ll)  ;
        b = ts_ttob2(-EB2,EB2,false,0ll) ;
        l = ts_ltor1(-EB2,EB2,true,0ll)  ;
        r = ts_ltor2(-EB2,EB2,false,0ll) ;

        ull l1, l2 ;
        l1 = ts_ttob1(-EB2,EB2,true,l) ;
        l2 = ts_ttob2(-EB2,EB2,false,l) ;

        ull r1, r2 ;
        r1 = ts_ttob1(-EB2,EB2,true,r) ;
        r2 = ts_ttob2(-EB2,EB2,false,r) ;

        ull t1, t2 ;
        t1 = ts_ltor1(-EB2,EB2,true,t) ;
        t2 = ts_ltor2(-EB2,EB2,false,t) ;

        ull b1, b2 ;
        b1 = ts_ltor1(-EB2,EB2,true,b) ;
        b2 = ts_ltor2(-EB2,EB2,false,b) ;

        // finding topmost point
        t = (t1+t2)/2ll ;

        // finding bottommost point
        b = (b1+b2)/2ll ;

        // finding leftmost point
        l = (l2+l1)/2ll ;

        // finding rightmost point
        r = (r2+r1)/2ll ;

        ll X,Y ;

        X = (l+r)/2 ;
        Y = (b+t)/2ll ;

        cout << X << ' ' << Y << endl ;

    }
    
}