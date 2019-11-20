#include <iostream>
#include <vector> 

using namespace std;

int main() {

    int n, h, x ;
    cin >> n >> h ; 
    vector< int > boxes(n), commands ;
    for ( auto i = 0 ; i < n ; ++i ) cin >> boxes[i] ;
    cin >> x ;
    while ( x ) {
        commands.push_back(x) ;
        cin >> x ;
    }

    int pos = 0 ;
    bool box = 0 ;

    for ( auto c : commands ) {

        switch ( c ) {

            case 1 :
                if ( pos != 0 ) 
                    pos-- ;
                break ;
                
            case 2 :
                if ( pos != n-1 ) 
                    pos++ ;
                break ;
            
            case 3 :
                if ( !box && boxes[pos] > 0 ) {
                    box = 1 ;
                    boxes[pos]-- ;
                } 
                break ;
            
            case 4 :
                if ( box && boxes[pos] < h ) {
                    box = 0 ;
                    boxes[pos]++ ;
                }
                break ;
            
            case 0 :
                break ;

        }

    }

    for ( auto c : boxes ) cout << c << " " ;



}