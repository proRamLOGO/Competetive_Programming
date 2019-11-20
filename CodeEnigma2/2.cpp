#include <bits/stdc++.h>
#define llui long long unsigned int
#define M 1000000007

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen("output.txt", "w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while ( t-- ) {
        llui n,k ;
        cin >> n  ;
        vector< int > arr(n) ;
        for ( auto i = 0 ; i < n ; ++i ) 
            cin >> arr[i];
        cin >> k ;

        int l=0, r=n-1 ;

        int rb = arr[r] ;
        int lb = 0 ;
        while ( l < r ) {
            while ( lb < rb*k && l <= r) {
                lb += arr[l++] ;
            }
            l++ ;
            r-- ;
        }

        if ( l==r ) 
            if ( lb > rb ) 
                cout << l+2 << ' ' << n-l-2 << endl ;
            else 
                cout << l+1 << ' ' << n-l-1 << endl ;  
        else 
            cout << l << ' ' << n-l << endl ; 
        

    }
}