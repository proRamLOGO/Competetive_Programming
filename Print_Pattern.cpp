#include <iostream>

using namespace std;

int main() {
    
    int t ;
    cin >> t ;
    while ( t-- ) {
        int n ;
        cin >> n;
        int l[ (n-1)*2 ] ;

        for ( auto i = 0 ; i < n-1 ; ++i ) {
            l[i] = i+1;
            l[2*n - 3 - i ] = i+1 ;
        }
        
        //for ( auto i = 0 ; i < 2*n - 2 ; ++i ) cout << l[i] << ' ' ;
        //cout << endl ;

        int x = 1, prev_y ;
        for ( auto i = 0 ; i < n ; ++i ) {

            cout << x << ' ' ;
            prev_y = x ;
            for ( auto y = 1 ; y < n ; ++y ) {

                cout << prev_y + l[i+(y-1)] << ' ';
                prev_y += l[i+(y-1)] ;
            }
            x += i+2 ;
            cout << endl ;

        }
    }

}