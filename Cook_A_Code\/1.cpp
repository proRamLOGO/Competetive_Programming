#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std ;

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        int n ;
        cin >> n ;
        vector< int > v(n) ;

        for ( auto i = 0 ; i < n ; ++i )
            cin >> v[i] ;

        sort( v.begin(), v.end() ) ;

        if ( n%2 == 0 ) {

            string code = "" ;

            for ( auto i = 1 ; i < n-2 ; i+=2 ) {

                int res = ( v[i+2] - v[i] ) ;
                ( res < 0 )? res *= -1 : 1 ;

                code += to_string(res) ;

            }

            code += to_string( v[n-1] - v[n-2] ) ;

            for ( auto i = n-2 ; i >= 2 ; i -= 2 ) {

                int res = ( v[i] - v[i-2] ) ;
                ( res < 0 )? res *= -1 : 1 ;

                code += to_string(res) ;

            }
            
            string code2 = code ;
            reverse( code.begin(), code.end() ) ;

            if ( code == code2 ) 
                cout << code << endl ;
            else 
                cout << "Key combination cannot be cracked\n" ;


        }

        else {

            string code = "" ;

            for ( auto i = 0 ; i < n-2 ; i+=2 ) {

                int res = ( v[i+2] - v[i] ) ;
                ( res < 0 )? res *= -1 : 1 ;

                code += to_string(res) ;

            }

            code += to_string( v[n-1] - v[n-2] ) ;

            for ( auto i = n-2 ; i >= 2 ; i -= 2 ) {

                int res = ( v[i] - v[i-2] ) ;
                ( res < 0 )? res *= -1 : 1 ;

                code += to_string(res) ;

            }

            code += to_string(v[1] - v[0]) ;
            
            string code2 = code ;
            reverse( code.begin(), code.end() ) ;

            if ( code == code2 ) 
                cout << code << endl ;
            else 
                cout << "Key combination cannot be cracked\n" ;


        }

    }

}