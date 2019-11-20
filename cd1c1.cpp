#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std ;

int main() {
    
    int t ;
    cin >> t ;
    
    for ( auto T = 0 ; T < t ; ++t ) {
        
        int n, msl = -1 ; ;
        bool ans = 1 ;
        
        cin >> n ;
        vector < bool > x(255,false) ;
        vector < string > str(n) ;
        
        //R=0, P=1, S=2
        vector< vector < bool > > d(3,x) ;
        
        for ( auto i = 0 ; i < n ; ++i ) {
            
            cin >> str[i] ;
            int ss = str[i].size() ;
            msl = max( msl,ss ) ;
            for ( auto j = 0 ; j < str[i].size() ; ++j ) {
                
                if ( str[i][j]=='R' ) 
                    d[0][j] = true ;
                if ( str[i][j]=='P' ) 
                    d[1][j] = true ;
                if ( str[i][j]=='S' ) 
                    d[2][j] = true ;
                
            }
            
        }
        //cout << msl << endl ;
        for ( auto i = 0 ; i < msl ; ++i ) {
            if ( d[0][i] && d[1][i] && d[2][i] ) {
                ans = 0 ;
                break ;
            }
        }
        
        if ( !ans ) {
            cout << "Case #" << T+1 << ": IMPOSSIBLE\n" ; 
            continue ;
        }
        
        string s="" ;
        
        /*cout << endl << endl ;
        
        for ( auto i : d ) {
            for ( auto j : i ) {
                cout << j << ' ' ;
            }
            cout << endl ;
        }
        
        cout << endl << endl ;
        */

        for ( auto i = 0 ; i < msl ; ++i ) {
            
            if ( !d[0][i] ) {
                if ( d[1][i] && !d[2][i] ) {
                    s += "S" ;
                }
                else if ( !d[1][i] && d[2][i] ) {
                    s += "R" ;
                }
                else {
                    s += "S" ;
                }
            }
            else if ( !d[1][i] ) {
                if ( d[0][i] && !d[2][i] ) {
                    s += "P" ;
                }
                else if ( !d[0][i] && d[2][i] ) {
                    s += "R" ;
                }
                else {
                    s += "R" ;
                }
            }
            else if ( !d[2][i] ) {
                if ( d[0][i] && !d[1][i] ) {
                    s += "P" ;
                }
                else if ( !d[0][i] && d[1][i] ) {
                    s += "S" ;
                }
                else {
                    s += "P" ;
                }
            }
            
        }
        cout << "Case #" << T+1 << ": " << s << "\n" ;
        
    }
    
}