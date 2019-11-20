#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std; 

long int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    long int t ;
    cin >> t ;
    while ( t-- ) {

        long int n, k, left = 0 ;
        cin >> n >> k ;
        float ans ;

        if ( n-(2*k) < 1 ) ans = 1.0 ;
        else if ( n-(2*k) == 1 ) ans = 2.0 ;
        else ans = n-(2*k) ;
        ans = 1.0 / ans ;

        cout << fixed << setprecision(6) << ans << endl ;

    }

}