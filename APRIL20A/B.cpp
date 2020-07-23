#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define left first
#define right second
#define MOD 1000000007d
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ulli;
typedef pair<ll, ll> pll;
typedef vector<ulli> vulli;
typedef vector<pll> vpll;
typedef vector<string> vs;

void pq( queue<int> q ) {
    while (!q.empty()) 
        cout << q.front() << ' ' , q.pop() ;
    
}

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
        vulli v(n);
        vector<int> store;
        
        //odd subarrays
        ulli p1=1, p2=1 ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            if ( v[i]!=0 and !(v[i]&1) ) store.pb(i) ;
        }

        int ans = n*(n+1)/2 ;
        // cout << ans << endl ;

        for ( int i = 0 ; i < store.size() ; ++i) {
            if ( v[store[i]]%4==2 ) {
                
                int left=0, right=0 ;
                
                if ( i == 0 ){
                    left = store[i] ;
                } else {
                    left = store[i] - (store[i-1]+1) ;
                }

                if ( i == store.size()-1 ) {
                    right = n-1-store[i] ;
                } else {
                    right = store[i+1] - (store[i]+1) ;
                }

                int inv = 1 + left + right + left*right ;
                // cout << inv << ' ' ;
                ans -= inv ;
            }

        }

        cout << ans << endl ;

    }

    return 0 ;
    
}