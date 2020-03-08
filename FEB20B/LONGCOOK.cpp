#include <bits/stdc++.h> 
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
 
typedef long long ll;
typedef unsigned long long ull;

int DB[] = {5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 1, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 6, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6} ;

ll searchh( ll x, bool e ) {
    if ( x <= 3) 
        return -1 ;
    if ( x <= 9)
        return 0 ;
    
    // # sum = 400
    // # len = 101
    
    x -= 9 ;
    ll t = x/400 ;
    ll rem = x%400 ;
    t *= 101 ;
    ll s = 0 ;
    ll i = 0 ;
    while ( i < 101 and s < rem ) {
        s += DB[i] ;
        i += 1 ;
    }
    if (e) 
        if ( s > rem ) 
            i -= 1 ;
    return t+i ;

}
ll countofcollisions(ll a, ll b) {
    ll low = searchh(a,false) ;
    ll hi = searchh(b,true) ;
    return hi-low+1 ;
}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t ;
    cin >> t ;
    while ( t-- ) {
    
        ll start_m, start_y, end_m, end_y ;
        cin >> start_m >> start_y >> end_m >> end_y ;
        
        if ( start_m > 2 )
            start_y += 1  ;
        if ( end_m == 1 )
            end_y -= 1 ;
        
        ll res = countofcollisions(start_y,end_y) ;
        cout << res << endl ;

    }

}