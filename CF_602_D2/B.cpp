#include <bits/stdc++.h>
#define llui long long unsigned int
#define lli long long int

using namespace std ; 

int main() {

    #ifndef ONLINE_JUDGE
        freopen( "input.txt", "r", stdin ) ;
        freopen( "output.txt", "w", stdout ) ;
    #endif

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    int t ;
    cin >> t ;

    while ( t-- ) {

        lli n ;
        bool ae = 1 ;
        cin >> n ;
        vector< lli > v(n), ans(n,0) ;
        vector< bool > p(n+1,0) ;
        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            if ( v[i]==0 ) 
                ae = 0 ;
        }

        if ( !ae ) {
            cout << -1 << endl ;
            continue ;
        }

        ans[0] = v[0] ;
        p[ans[0]] = 1 ;
        
        for ( auto i = 1 ; i < n ; ++i ) {

            if ( v[i-1] == v[i] ) {
                bool fnd = 0 ;
                for ( auto j = v[i]-1 ; j > 0 ; --j ) {
                    if ( !p[j] ) {
                        fnd = 1;
                        ans[i] = j ;
                        p[j] = 1 ;
                        break ;
                    }
                }
                if ( !fnd ) {
                    ae = 0 ;
                    break ;
                }
            }
            else if ( v[i-1] < v[i] ) {
                p[v[i]] = 1 ;
                ans[i] = v[i] ;
            }

        }

        if ( !ae ) {
            cout << -1 << endl ;
            continue ;
        }

        for ( auto i : ans )
            cout << i << ' ' ;
        cout << endl ;

    }

    return 0 ;

}