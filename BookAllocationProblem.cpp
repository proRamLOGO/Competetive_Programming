#include <bits/stdc++.h>

using namespace std ; 

bool f( int arr[], int n, int b, int p ) {

    int cp = 0 ;
    for ( auto i = 0 ; i < n ; ++i ) {

        if ( arr[i] > p )
            return false ;
        
        if ( arr[i]+cp > p ) {
            cp = arr[i] ;
            --b ;
            if ( b==0 )
                return false ;
        }
        else 
            cp += arr[i] ;

    }
    return true ;

}

int binarySearch( int arr[], int n, int b ) {

    int sum = 0 ;
    for ( int  i = 0 ; i < n ; ++i )
        sum += arr[i] ;
    
    int lo = 1, hi = sum, mid, ans = INT_MAX ;

    while ( hi >= lo ) {

        int mid = ( lo + hi ) / 2 ;

        if ( f( arr, n, b, mid ) ) {
            hi = mid - 1 ;
            ans = min(ans,mid) ;
        }
        else 
            lo = mid + 1 ;

    }

    return ans ;

}

int main() {

    #ifndef ONLINE_JUDGE
        freopen( "input.txt", "r", stdin ) ;
        freopen( "output.txt", "w", stdout ) ;
    #endif

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int t ;
    cin >> t ;
    while ( t-- ) {
        int n, x ;
        cin >> n >> x ;
        int arr[n] ;
        for ( auto j = 0 ; j < n ; ++j )
            cin >> arr[j] ;
        cout << binarySearch(arr,n,x) << endl ;
    }
}

