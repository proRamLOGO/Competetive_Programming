#include <iostream>
#include <string>

using namespace std ;

int main () {

    int t ;
    cin >> t ;
    while ( t-- ) {

        string s ;
        cin >> s ;
        int g=0,r=0 ;

        for ( auto c : s ) ( c == 'R' ) ? r++ : g++ ;

        if ( s.length() == 1 ) cout << "yes\n" ;
        else if ( s.length()%2 == 0 &&  g == r ) cout << "yes\n" ;
        else if ( s.length()%2 != 0 &&  g < r && g+1 == r ) cout << "yes\n" ;
        else if ( s.length()%2 != 0 &&  g > r && r+1 == g ) cout << "yes\n" ;
        else cout << "no\n" ;


        if ( s.length() == 1 ) {
            cout << "yes\n" ;
            continue ;
        }

        char it = s[0] ;
        int mis = -1 ;

        for ( auto c : s ) {
            if ( c == it ) 
               ++mis ;
            else 
                it = c ;
        }

        if ( mis%2 == 0 || mis == 1) cout << "yes\n" ;
        else cout << "no\n" ;

    }

} 