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
        //[l,l+k-1]

        int n, k ;
        cin >> n >> k ;
        vll v(n) ; vector<int> idx ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i>0 and i<n-1 and v[i-1] < v[i] and v[i+1] < v[i] ) 
                idx.pb(i+1) ;
        }

        int nop = 0, al = 0, ar = 0 ;

        // for ( auto i : idx) cout << i << " " ;
        // cout << endl ;

        if ( idx.size() == 0 ) {
            cout << "1 1" << endl ;
            continue ; 
        }

        for ( int i = 0 ; i < idx.size() ; ++i ) {

            int l = idx[i]-1 ;
            int r = l+k-1 ;

            auto itr = lower_bound(allv(idx),r) ;
            int ri = itr-idx.begin() ;
            --ri ;
            // cout << l << " " << r << " " << ri << endl ;

            if ( ri-i+1 > nop ) {
                nop = ri-i+1 ;
                al = i ;
                ar = ri ;
            }

        }
        // cout << al << " " << ar  << endl ;
        int pos = max( idx[ar]-k+2,1 ) ;

        cout << nop+1 << ' ' << pos << endl ;

        


    }

    return 0 ;
    
}