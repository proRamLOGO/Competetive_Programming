#include <iostream>

using namespace std;
int sqrt_floor( int num ) {

    int mid , ans , hi = num , lo = 1;
    while( hi >= lo ) {

        mid = ( hi + lo ) / 2 ;
        if ( mid*mid <= num ) {
            ans = mid ;
            lo = mid + 1 ;
        }
        else hi = mid - 1;

    }
    return ans ;

}

int isP( int n ) {

    int i=0;

    float lo = sqrt_floor( n );
    float hi = lo + 1 ;
    float mid;
    while ( i < 100) {
        ++i ;
        mid = ( hi + lo ) / 2 ;
        if ( mid*mid < n ) lo = mid ; 
        else hi = mid ;

    }
    
    cout << mid << endl ;

}