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
    
    for ( int T = 1 ; T <= t ; ++T ) {
        
        // Code here

        int n ; 
        cin >> n ;
        vector< vector< int > > v(n,vector<int>(n)) ;

        int sum = 0;

        for ( int i = 0 ; i < n ; ++i )
            for ( int j = 0 ; j < n ; ++j ) {
                cin >> v[i][j] ;
                if ( i==j )
                    sum += v[i][j] ;
            }


        int r = 0, c = 0 ;
        // rows
        for ( int i = 0 ; i < n ; ++i ) {
            vector<bool> p(n+1,false) ;
            for ( int j = 0 ; j < n ; ++j ) {
                if ( p[v[i][j]] == true ) {
                    ++r ;
                    break ;
                }
                p[v[i][j]] = true ;
            }
        }
        // colums
        for ( int i = 0 ; i < n ; ++i ) {
            vector<bool> p(n+1,false) ;
            for ( int j = 0 ; j < n ; ++j ) {
                if ( p[v[j][i]] == true ) {
                    ++c ;
                    break ;
                }
                p[v[j][i]] = true ;
            }
        }

        cout << "Case #" << T << ": " << sum << ' ' << r << ' ' << c << endl ;
        
    }
    
}