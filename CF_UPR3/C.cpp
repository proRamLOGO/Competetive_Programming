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

bool sufficient( ll r, vpll &myt, vll &v, vll &t ) {
    
    // cout << "here" << endl ;
    for ( int i = 0 ; i < len(v) ; ++i ) {
        // cout << myt[i].first << ' ' << v[i]-r << ' ' << myt[i].second << ' ' << v[i] + r << endl ;
        if ( !( ( ( myt[i].first < v[i] ) and ( v[i]-r <= myt[i].first ) ) or ( ( myt[i].second > v[i] ) and ( v[i]+r >= myt[i].second ) ) ) )
            return false ;
    }


    return true ;

}

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int T =1;
    // cin >> t ;

    while ( T-- ) {

        int n, m ;
        cin >> n >> m ;
        vll v(n), t(m) ;
        for ( int i = 0 ; i < n ; ++i ) cin >> v[i] ;
        for ( int i = 0 ; i < m ; ++i ) cin >> t[i] ;

        vpll myt(n) ;

        for ( int i = 0 ; i < n ; ++i ) {
            int idxl, idxr ;
            vll::iterator itr = lower_bound(allv(t),v[i]) ;
            
            // cout << itr-t.begin() << ' ';

            if ( itr==t.end() )
                idxl = idxr = t[m-1] ;
            else {
                if ( *itr > v[i] ) {
                    idxr = itr-t.begin() ;
                    if ( idxr > 0 ) 
                        idxl = t[idxr-1] ;
                    else
                        idxl = t[idxr] ; 
                    idxr = t[idxr] ;

                } else 
                idxr = idxl = t[itr-t.begin()] ;
            }
            // cout << idxl << " " << idxr << endl;
            if ( idxl > v[i] )
                idxl = v[i] ;
            if ( idxr < v[i] )    
                idxr = v[i] ;
            myt[i] = mp(idxl,idxr) ;
        }
        // cout << "Made myt \n\n" << endl ;
        ll lo = 0, hi = max( v[n-1]-t[0] , t[m-1] - v[0] ), ans = hi ;

        while ( hi >= lo ) {

            ll mid = (hi+lo)/2 ;
            
            // cout << "*********" << endl  ;
            // cout << hi << " " << lo <<" "<<mid << endl ;

            if ( sufficient(mid,myt,v,t) ) {
                // cout << "isfit" << endl ;
                ans = min(ans,mid) ;
                hi = mid-1 ;
            } 
            else 
                lo = mid+1 ;

        }

        cout << ans << endl ;

    }

    return 0 ;
    
}