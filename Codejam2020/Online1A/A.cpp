#include <bits/stdc++.h>
#define pb push_back
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

        int n, ml=0 ; 
        cin >> n ;
        vector< string > v(n) ;

        bool cat1 = true, cat2 = true ;

        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            bool af = false ;
            
            if ( cat1 )
            for ( auto j : v[i] ) {
                if ( j=='*' ) {
                    if ( af == true ) {
                        cat1 = false ;
                        cat2 = false ;
                        break ;
                    }
                    af = true ;
                }
            }
            if ( af and v[i][0]!='*' )
                cat1 = false ;

            if ( v[ml].size() < v[i].size() )
                ml = i ;

        }

        if ( cat1 ) {
        string ans = "" ;
        bool valid = true ;
            // int end = ml-1 ;
            for ( int i = v[ml].size()-1 ; i > 0 ; --i ) {
                char c = v[ml][i] ;
                for ( int j = 0 ; j < n ; ++j ) {
                    if ( v[j].size() > v[ml].size()-i-1 ) {
                        if ( v[j][v[j].size()-(v[ml].size()-i)]!=c and v[j][v[j].size()-(v[ml].size()-i)]!='*' ) {
                            // cout << i << ' ' << j << endl ;
                            valid = false ;
                            break ;
                        }
                    }
                }
                ans = string(1,c) + ans ;
                if (!valid) break ;
            }
        
        if(!valid) ans="*" ;
        cout << "Case #" << T << ": " << ans << endl ;
        }

        else if (cat2) {
            
        }

    }
    
}