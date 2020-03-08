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
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

int32_t maxprofit( vvll plan , vector<bool> time_available, vector<bool> show_available, int32_t cost, int mx ) {

    // Base Case 
    if ( !( time_available[0] or time_available[1] or time_available[2] or time_available[3] ) ) {
        // cout << "1 Returning cost = " << cost << endl << endl ;
        return cost ;
    }

    // int max_req_i = -1, max_req_j = -1 ;

    bool went = false ;
    int32_t ans = INT32_MIN ;
    
    for ( int i = 0 ; i < 4 ; ++i ) {
        if ( show_available[i] ) {
        for ( int j = 0 ; j < 4  ; ++j ) {
            if ( time_available[j] ) { 
            if ( plan[i][j] != 0 ) {
                went = true ;
                time_available[j] = false ;
                show_available[i] = false ;
                // cout << plan[i][j] << " Choosing " << i << ' ' << j << " at " << 25*mx << endl  ;
                ans = max( ans, maxprofit(plan,time_available, show_available,cost+(plan[i][j]*(25 * mx)), mx-1 ) ) ;
                time_available[j] = true ;
                show_available[i] = true ;
            }
            }
        }
        }
    }

    if ( !went )
        ans = cost - (100*mx) ;

    // cout << "2 Returning cost = " << ans << endl << endl ;
    return ans ;


}

int32_t solve( vvll plan ) {

    return maxprofit( plan, vector<bool>(4,true), vector<bool>(4,true), 0, 4 ) ;

}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    uint8_t t ;
    cin >> t ;
    t -= '0' ;
    
    int32_t gans = 0 ;

    while ( t--!=0 ) {

        // Inputs and prep
        uint32_t n ;
        cin >> n ;

        if ( n==0 ) {
            gans += -400 ;
            cout << -400 << endl ;
            continue ;
        }

        vvll plan( 4, vll(4,0) ) ;

        for ( auto i = 0 ; i < n ; ++i ) {
            uint8_t movie ;
            uint16_t tim ;
            cin >> movie >> tim ;
            movie -= 'A' ;
            tim = (tim%12) / 3 ;
            ++plan[movie][tim] ;
        }

        int32_t ans = solve( plan ) ;
        cout << ans << endl ;

        gans = gans + ans ;

    }

    cout << gans << endl ;
    
    return 0 ;

}