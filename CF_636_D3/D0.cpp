#include <bits/stdc++.h> 
#include <unordered_set> 
#include <map>
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

        int n,k ;
        cin >> n >> k ;
        
        vll v(n) ;
        for ( int i = 0 ; i < n ; ++i ) cin >> v[i] ;
        map<ll,int> sumfreq ;
        ll me = *min_element(allv(v)) ;
        for ( int i = 0 ; i < n/2 ; ++i) {
            ++sumfreq[ v[i]+v[n-i-1] ] ;
        }

        vector<int> cf;
        cf.pb(sumfreq.begin()->second) ;
        bool f = 0 ;
        for ( auto i : sumfreq ) {
            if (!f) {
                f=1 ;
                continue ;
            }

            cf.pb(cf[len(cf)-1]+i.second) ;
        }

        for ( auto i : cf ) cout << i << " " ;
        cout << endl ;cout << endl ;

        int ans = n+n ;
        int c = 1 ;
        f=0 ;
        for ( auto i : sumfreq ) {
            cout << endl << i.first << " " << i.second << "  :  " ;
            ll req = i.first-k ;

            if ( req<0 ) {
                ans = min(ans,2*(cf[len(cf)-1]-i.second)) ;
                continue ;
            }

            cout << req << ' ' ;
            auto pos = sumfreq.lower_bound(req) ;
            int idx = distance(sumfreq.begin(),pos) ;
            cout << pos->first << endl ; 
            cout << idx << ' ' ;
            if ( pos->first>req  ) 
                idx-- ;
            cout << idx << ' ' ;
            int nans = 0 ;
            if ( idx>-1 ) 
                nans = cf[idx] ;
            
            nans += (cf[len(cf)-1] - i.second) ;
            cout << cf[len(cf)-1] - i.second << "   nans = " << nans << endl ; 
            ans = min(ans,nans) ;
            ++c ;
        }
        cout << ans << endl ;

    }

    return 0 ;
    
}
// 17
// 4 2
// 1 2 1 2
// 4 3
// 1 2 2 1
// 8 7
// 6 1 1 7 6 3 4 6
// 6 6
// 5 2 6 1 3 4
// 2 1
// 1 1
// 2 2
// 1 1
// 2 2
// 1 2
// 2 2
// 2 1
// 2 2
// 2 2
// 4 1
// 1 1 1 1
// 4 2
// 1 1 1 1
// 4 2
// 1 1 1 2
// 4 2
// 1 1 2 1
// 4 2
// 1 1 2 2
// 4 2
// 1 2 1 1
// 4 2
// 1 2 1 2
// 4 2
// 1 2 2 1