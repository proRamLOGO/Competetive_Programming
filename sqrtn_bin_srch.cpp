#include <iostream>

using namespace std;

int isP( int n ) {

    int hi = n;
    int lo = 1;
    int mid,ans = n;
    while( hi >= lo ) {
        mid = (hi+lo) / 2 ;

        if ( mid*mid <= n ) {
            ans = mid ;
            lo = mid + 1 ;
        }
        else hi = mid - 1 ;
    }

    return (n == ans*ans) ? ans : -1  ;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen( "output.txt", "w", stdout ) ;
    #endif

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int t ;
    cin >> t ;

    while ( t-- ) {
        int n, cnt=0 ;
        cin >> n ;
        while ( n!=1 ) {
            ++cnt ;
            cnt%=2 ;
            int res = isP(n) ;
            if( res != -1 ) 
                n = res ;
            else 
                n -= 1 ;
        }
        cout << cnt << endl ;
    }

}