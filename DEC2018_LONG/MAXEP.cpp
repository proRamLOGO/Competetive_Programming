#include <iostream>
#include <vector>

using namespace std;

int main( ) {

    int coins = 1000 ,n ,x ,y ,c ,q ;

    cin >> n >> c ;

    int hi = n , lo = 1 ;
    int mid ;

    while ( hi >= lo && coins > 0 ) {

        mid = (hi+lo) / 2 ;
        cout << 1 << ' ' << mid << endl ;

        cin >> q ;

        if ( q == 0 ) 
            lo = mid+1 ;

        else if ( q == 1 ) {
            hi = mid-1 ;
            coins -= c ;
            cout << 2 << endl ;
        }

        coins-- ;

    }

    if ( q == 1 ) x = mid ;
    else if ( q == 0 ) x = mid+1 ;

    cout << 3 << ' ' << x << endl ;


}