#include <bits/stdc++.h>
#define llui long long unsigned int 

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

    while ( t-- ) {

        int n, k ;
        bool ans = true ;
        cin >> n >> k ;
        vector< llui > v(n) ;
        unordered_map< llui, int > checker ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            if ( ans )
                checker[v[i]]++ ;
            if ( checker[v[i]] > 1 and v[i] != 0 ) {
                ans = false ;
            }
        }

        if ( !ans ) {
            cout << "NO" << endl ;
            continue ;
        }

        vector< bool > power( 20, false ) ;

        for ( int  )

        


    }

}
