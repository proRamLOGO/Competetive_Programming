#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int n ;
    cin >> n ;

    for ( auto i = 0 ; i < n ; ++i ) 
        cout << '*' ;
    
    cout << "\n" ;

    for ( auto i = 0 ; i < n/2 ; ++i ) {

        for ( auto y = 0 ; y < n/2 - i ; ++y ) 
            cout << '*' ;

        for ( auto y = 0 ; y < 2*(i+1) - 1 ; ++y )
            cout << ' ' ;
        
        for ( auto y = 0 ; y < n/2 - i ; ++y ) 
            cout << '*' ;
        
        cout << endl ;
    }

    for ( auto i = 0 ; i < n/2 - 1 ; ++i ){

        for ( auto y = 0 ; y < i+2 ; ++y ) 
            cout << '*' ;

        for ( auto y = 0 ; y < 2*( n/2 - i-1) - 1 ; ++y )
            cout << ' ' ;

        for ( auto y = 0 ; y < i+2 ; ++y ) 
            cout << '*' ;

        cout << endl ;

    }

    for ( auto i = 0 ; i < n ; ++i ) 
        cout << '*' ;
    

    return 0;
}
