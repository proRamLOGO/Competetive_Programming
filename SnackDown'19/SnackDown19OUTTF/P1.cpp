#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t ;
    while ( t-- ) {

        long int n,k;
        cin >> n >> k ;
        vector< long long int > arr(n);
        for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;
        sort(arr.rbegin(), arr.rend());

        long long int score = arr[k-1] ;

        long long int hi = n-1 , lo = 0 , mid , ans ;

        while ( hi >= lo ) {
            mid = (hi+lo) / 2 ;

            if( arr[mid] < score ) hi = mid - 1 ;
            else if ( arr[mid] == score ) {
                ans = mid ;
                lo = mid + 1 ;
            }
            else lo = mid + 1 ;

        }

        cout << ans+1 << endl ;

    }

}