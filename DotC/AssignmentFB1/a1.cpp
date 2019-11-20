#include <iostream>

using namespace std; 

int main() {

    int n ;
    cin >> n ;

    for ( auto i = 0 ; i < n/2 + 1 ; ++i ) {

        for ( auto y = i ; y < n/2 ; ++y ) 
            cout << ' ' ;
        
        for ( auto y = 1 ; y <= 2*i - 1 ; ++y ) 
            cout << "*" ;
        
        cout << "\n" ;

    }

    for ( auto i = 0 ; i < n/2 ; ++i ) {

        for ( auto y = i+1  ; y > 0 ; --y )
            cout << ' ' ;
        
        for ( auto y = 2 * ( n/2 - i - 1 ) - 1  ; y > 0  ; --y ) {
            cout << '*' ;
        }

        cout << "\n" ;

    }


}