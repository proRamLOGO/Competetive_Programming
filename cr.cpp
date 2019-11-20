#include <iostream>
#define lli long long int
using namespace std;

lli sqrt_floor( lli num ) {

    lli mid , ans , hi = num , lo = 1;
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

float sqrt( lli n ) {

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
    
    return mid ;

}
int main() {

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen( "output.txt", "w", stdout ) ;
    #endif

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    lli t ;
    cin >> t ;

    while ( t-- ) {
        lli n, cnt=0 ;
        cin >> n ;
        while ( n!=1 ) {
            // cout << n << "->" ;
            
            // cnt%=2 ;
            float res = sqrt(n) ;
            // cout << "Calculation for n = " << n << "   from func " << res <<endl ;
            // cout << endl << n << " <-> " << res << endl ;
            if( (int)res*(int)res == n ) {
                // cerr << "in first block\n" ;
                n = res ;
                // cout << "n is a prefect suare, n red to " << n << endl ;
            }
            else {
                // cerr << "in sec block\n" ;
                lli b = (int)res*(int)res ;
                cnt += (n-b) ;
                // cout  << n << " : " <<b << endl << endl ;
                n = b ;
            }
            if (n==2) {
                ++cnt ;
                // cnt %= 2 ;
                break ;
            }
            ++cnt ;
            // cerr << n << endl ;
        }
        cout << cnt%2 << endl ;
    }

}