#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

long int b_search( vector<long int> arr , long int ele , long int lo, long int hi ) {

    long int ans = -1 ;
    long int mid ;
    ++lo ;
    while ( hi >= lo ) {

        mid = ( hi+lo ) / 2 ;

        if ( arr[mid] < ele ) {
            ans = mid ;
            lo = mid+1 ;
        }
        else if ( arr[mid] >= ele ) hi = mid-1 ;
    
    }

    return ans ;

}

int main() {

    long int n, k ;
    cin >> n >> k ; 
    vector< long int > arr(n) ;
    for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;

    sort(arr.begin(),arr.end()) ;

    long int ans = 0 ;

    for ( auto i = 0 ; i < n ; ++i ) {

        long int x = k - arr[i] - 1 ;
        x = b_search( arr, x, i, n ) ;
        if ( x != -1 ) 
            ans += ( x-i ) ;

    }

    cout << ans ;

}