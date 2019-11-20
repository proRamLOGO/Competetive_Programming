#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

bool cmp( int x, int y ) {
    return x >= y ;
}


int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        string s ;
        cin >> s ;
        
        vector< int > alpha(25,0) ;

        for ( auto c : s ) {

            int j = c - '0' ;
            j -= 17 ;
            ++alpha[j] ;

        }

        sort( alpha.begin(), alpha.end(), cmp ) ;

        alpha.resize( s.length() ) ;

        /*for ( auto c : alpha ) 
            cout << c << ' ' ;
        */
        //cout << endl ;

        int n = s.length(), ans = INT32_MAX, res=0  ;

        for ( auto i = 1 ; i <= n ; ++i ) {
            
            //cout << i << endl ;
            if ( n%i == 0 ) {
                //cout << i << ' is a factor\n' ;
                res = 0 ;
                for ( auto y = 0 ; y < (n/i) ; ++y ) {
                    if ( alpha[y]!=0  ) {
                    ( alpha[y] <= i )? res += (i - alpha[y]) : res += (alpha[y] - i) ;
                    }
                }
                ans = min( ans,res ) ;
            }

        }

        
        cout << ans << endl ;

    }

}