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

int findMaxLength(vector<int>& nums) {
        
    unordered_map< int, vector<int> > idx ;
    int z=0,o=0 ;
    int ans = 0 ;
    for ( int i = 0 ; i < nums.size() ; ++i ) {
        if ( nums[i]==0 ) 
            ++z ;
        else
            ++o ;
        
        // if ( z!=0 and o!=0 ) {
            idx[z-o].push_back(i) ;
            if (z==o) {
                ans = i+1 ;
            }
        // }
    }
    
    for ( auto i : idx ) {
        vector<int> indices = i.second ;
        if ( indices.size() > 1 ) {
            int k = indices[indices.size()-1]-indices[0] ;
            if ( indices[0]>0 ) {
                if ( nums[indices[0]-1]+nums[indices[0]] == 1 )
                    k += 2 ;
            }
            ans = max(ans,k) ;
        }
    }
    
    if (ans==0 and z!=0 and o!=0 )
        ans = 2 ;
    
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
        for( int i = 0 ; i < n ; ++i ) cin >> v[i] ;
        cout << findMaxLength(v) ;

    }

    return 0 ;

}
