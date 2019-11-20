#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std ;

bool cmp( int x, int y ) {
    return x > y ;
}

int print( vector<int>& v, int l , int r) {

    cout << endl ;
    for ( auto i = l ; i < r ; ++i )
        cout << v[i] << ' ' ;
    cout << endl ;

}

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        int n, k, x ;
        cin >> n >> k ;
        vector< int > stk ;
        vector< int > s(k);

        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> x ;
            stk.push_back(x) ;
        }
        for ( auto i = 0 ; i < k ; ++i )
            cin >> s[i] ;

        sort( s.begin(), s.end(), cmp ) ;
        /*
        cout << "stk = " ; 
        print(stk, 0, n) ;    
        
        
        cout << "Now S = " ; 
        print(s, 0, k) ;
*/
        int itr = 0, turn = 0 ;
        int chef = 0, garry = 0;


        for ( auto i = 0 ; i < n ; ++i){

            while ( s[itr] > n-i ) {
                ++itr ;
            }

            /*if ( turn ) {
                cout << "Garry will take top " << s[itr] << " elements\n" ;
            }
            else {
                cout << "Chef will take top " << s[itr] << " elements\n" ;
            }

            
            cout << "\nstk before deletion " ; 
            print(stk, i, n) ;*/

            int j ;
            for ( j = 0 ; j < s[itr] ; ++j ) {
                
                if ( turn ) {
                    garry += pow(2,stk[i+j]) ;
                }
                else{
                    chef += pow(2,stk[i+j]) ;
                } 
                
            }

            i += j ;      
            turn = (++turn)%2 ;
            /*cout << "\nChef score = " << chef << endl ;

            cout << "\nGarry score = " << garry << endl ;

            cout << "\nstk after deletion " ; 
            print(stk, i, n) ; */
            --i ;

        }
        
        if ( garry == chef ) 
            cout << "Draw\n" ;
        else if ( garry < chef ) 
            cout << "Chef\n" ;
        else 
            cout << "Garry\n" ;
        
        
    }

}