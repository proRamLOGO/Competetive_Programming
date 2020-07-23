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

int digits( ll n ) {
    
    int cnt = 0 ;
    while ( n!=0 ) {
        ++cnt ;
        n >>= 1;
    }
    return cnt ;
    
}


int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t =1;
    cin >> t ;

    while ( t-- ) {
        
        int n ;
        cin >> n;
        vector<int> v(n), loc(n+1,-1) ;
        vector<bool> visited(n,false) ;
        
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            loc[v[i]] = i ;
        }

        bool ans = true ;

        for ( int i = 1 ; i <= n ; ++i ) {

            if ( !visited[i] ) {
                // cout << "Inside " << i << '\n' ;
                int idx = loc[i] ;
                visited[idx] = true ;
                for ( int j = 1+idx ; j<n and !visited[j] ; ++j ) {
                    if ( v[j]-1 != v[j-1] ) {
                        ans = false ;
                        break ;
                    }
                    // cout << "Marking " << v[j] << ", " ;
                    visited[j] = true ;
                }
                if ( !ans ) break ;

            }
            // cout << endl ;
            // for ( auto j : visited )
            //     cout << j << ' ' ;
            // cout << endl ;

        }
        // cout << endl ;

        if (ans)
            cout << "Yes" << endl ;
        else 
            cout << "No" << endl ;
        
        // cout << "================================" << endl ;
    }

    return 0 ;
    
}