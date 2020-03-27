#include <bits/stdc++.h> 
#define allv(v) v.begin(), v.end()
#define ulli unsigned long long int
#define pb push_back

using namespace std;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t ;
    cin >> t ;
    
    while ( t--!=0 ) {

        // Inputs
        int n, q ;
        cin >> n >> q ;
        
        unordered_map< ulli, vector<int> > intersections ;

        for ( int i = 0 ; i < n ; ++i ) {
            ulli y1, y2 ;
            for ( auto y = y1 ; y <= y2 ; ++y ) {
                // intersections[y].pb()
            }
        }

    }
    
    return 0 ;

}