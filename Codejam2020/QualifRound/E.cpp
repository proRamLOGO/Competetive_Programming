#include <bits/stdc++.h>
#define st first
#define en second
#define mt make_tuple
#define llui long long unsigned int
#define allv(v) (v.begin(),v.end())

using namespace std ;

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t ;
    cin >> t ;
    
    for ( int T = 1 ; T <= t ; ++T ) {
        
        int n, k ;
        cin >> n >> k ;

        if ( k%n != 0 ) {
            cout << "Case #" << T << ": IMPOSSIBLE" << endl ;
            continue ;
        }

        cout << "Case #" << T << ": POSSIBLE" << endl ;

        int q = k/n ;

        if ( q==n+1 ) {
            for ( int i = 0 ; i < n ; ++i ) {
                for ( int j = 0 ; j < n ; ++j ) {
                    cout << (i*n + j)%4 + i; 
                }
                cout << endl ;
            }
        }

    }
    
}