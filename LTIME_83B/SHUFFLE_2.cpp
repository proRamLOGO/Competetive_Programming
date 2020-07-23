#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
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

int32_t main() {
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t ;
    cin >> t ;

    while( t-- ) {
        
        int n, k ;
        cin >> n >> k;
        vll v(n), vs(n) ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            vs[i] = v[i] ;
        }
        sort(allv(vs)) ;
        bool res = true ;
        for ( int i = 0 ; i < n ; ++i ) {
            ll target = v[i] ;
            // cout << target << " " << i << endl ;
            if ( target == vs[i] ) continue ;
            
            bool put = false ;
            for ( int j = i+k ; j < n ; j+=k ) {
                // cout << "    Trying " << j << " for " << target << endl ;
                if ( vs[j]!= -1 and target == vs[j] ) {
                    vs[j] = -1 ;
                    put = true  ;
                    // cout << "    ==Putted " << target << " at " << j << endl ;
                    break ;
                    
                }
            }
            for ( int j = i-k ; !put and j > -1 ; j-=k ) {
                // cout << "    Trying " << j << " for " << target << endl ;
                if ( vs[j]!= -1 and target == vs[j] ) {
                    vs[j] = -1 ;
                    put = true  ;
                    // cout << "    ==Putted " << target << " at " << j << endl ;
                    break ;
                    
                }
            }
            if ( !put ) { 
                res = false ;
                break ;
            }

        }

        if (res)
            cout << "yes" << endl ;
        else
            cout << "no" << endl ;

            // cout << "==================" << endl ;

    }

    return 0 ;

}
