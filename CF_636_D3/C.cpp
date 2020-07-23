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

        int n ;
        cin >> n ;
        vll v(n) ;
        for ( int i = 0 ; i < n ; ++i ) cin >> v[i] ;
        
        vll ss ;
        bool pos = (v[0]>0) ;

        ll le = v[0] ;
        // cout << "pos" << pos << endl ;
        for ( auto i : v ) {
            
            // cout << i <<' '  ;
            if ( ( i<0 and pos ) or ( i>0 and !pos ) ) {
                pos = (pos==0)?1:0 ;
                ss.pb(le) ;
                le = i ;
                // cout << le <<' ' <<pos   ;
            }
            else if ( i>le ) 
                le = i ;
            // cout << endl ;
                
        }
        // cout << endl ;

        if ( ss.size()==0 ) ss.pb(le) ;
        if ( ss.size()>0 and (ss[len(ss)-1]*le <0)  ) ss.pb(le) ;

        // if ( ss.size()==0 ) {
        //     cout << (*max_element(allv(v))) << endl ;
        //     continue ;
        // }

        ll sum=0 ;
        for ( auto i : ss )
            sum += i;
        cout << sum << endl ;

    }

    return 0 ;
    
}