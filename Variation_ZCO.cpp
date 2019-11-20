#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int b_search( vector<int> arr , int ele ) {

    int hi = arr.size() ;
    int lo = 0 ;
    int ans = -1 ;
    int mid ;

    while ( hi >= lo ) {

        mid = ( hi+lo ) / 2 ;

        if ( arr[mid] <= ele ) {
            ans = mid ;
            lo = mid+1 ;
        }
        else if ( arr[mid] > ele ) hi = mid-1 ;
    
    }

    return ans ;

}

int main() {

    int n, k ;
    cin >> n >> k ; 
    vector< int > arr(n) ;
    for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;

    sort(arr.begin(),arr.end()) ;

    int ans = 0 ;

    for ( auto i=0, j=i+1 ; i < n-1 ; ) {

        if ( abs(arr[i]-arr[j]) >= k ) {
            ans += n-j ;
            ++i ;
        }
        else 
            ++j ;

    }

    cout << ans ;

}