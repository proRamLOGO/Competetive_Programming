#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;

    while ( t-- ) {

        int n,k;
        cin >> n >> k ;
        vector < int > arr(n) ;
        for( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;
        int ans=0;

        vector< int > dp(n-k+1) ;

        for( auto i = 0 ; i < k ; ++i ) dp[0] += arr[i] ;
        for( auto i = 1 ; i <= n - k ; ++i ) dp[i] = dp[i-1] - arr[i-1] + arr[i+k-1] ;
        int max=INT8_MIN ;

        for( auto i = 0 ; i < n - k + 1 ; ++i ) if( dp[i] >= max ) max = dp[i] ;

        cout << max << endl ;


    }

}