#include <bits/stdc++.h> 
#include <unordered_set> 
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

int maxProfit(vector<int>& prices) {
    
    prices.push_back(0) ;
    int ans = 0 ;
    int last = 0 ;
    for ( int i = 0 ; i < prices.size()-1 ; ++i ) {
        if ( prices[i] > prices[i+1] ) {
            if ( i!=0 ) {
                int p = prices[i] - prices[last] ;
                if ( p > 0 ) {
                    ans += p ;
                }
            }
            last = i+1 ;
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
    // cin >> t ;

    while( t-- ) {
        
        int n;
        cin >> n ;
        vector<int> v(n) ;
        for ( int i=0 ; i < n ; ++i ) cin >> v[i] ;
        maxProfit(v) ;
            
    }

    return 0 ;

}
