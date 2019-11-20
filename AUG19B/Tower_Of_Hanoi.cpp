#include <iostream>

using namespace std ;

void TOH( int n, char s, char h, char d ) {

    if ( n==0 )
        return ;

    TOH( n-1, s, h, d ) ;
    cout << "Move " << n << " to " << d ;
    TOH( n-1, h, s, d ) ;

}

int main() {

    int n ;
    cin >> n ;
    TOH( n, 'A', 'B', 'C' ) ;

}