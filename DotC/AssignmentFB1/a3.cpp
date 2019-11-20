#include <iostream>

using namespace std ;

int main(int argc, char const *argv[])
{
    
    int n ;

    cin >> n ;
    cout << 1 << endl ;
    for ( auto i = 1 ; i <= n ; ++i ) {

        cout << i ;
        for ( auto y = 1 ; y < i ; ++y ){

            cout << 0 ;

        }
        cout << i << endl ; 

    }

    return 0;
}
