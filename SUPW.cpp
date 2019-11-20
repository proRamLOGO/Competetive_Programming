#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int rec( vector< int >& arr, vector< vector <int> >& dp, int ind, int rest ) {

    if ( rest == 3 ) 
        return INT_MAX ;
    if ( ind == arr.size() ) 
        return 0 ;

    if ( dp[ind][rest] != -1 ) 
        return dp[ind][rest] ;
    else 
        return dp[ind][rest] = min( arr[ind]+rec( arr, dp, ind+1,0), rec( arr, dp, ind+1,rest+1) ) ;

}
//
int main() {

B
HSHSHBVJSKSJG
VECTOR <INT >

    int n ;
    cin >> n ;

    vector< int > arr(n) ;
    vector < vector < int > > dp( n, vector< int > (3) ) ;

    for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;s

    for ( auto i = 0 ; i < n ; ++i ) {
        dp[i][0] = 2 ;
        dp[i][1] = 1 ;
        dp[i][2] = -1 ; 
    }
    dp[n-1][2] = arr[n-1] ;

    int ans = rec( arr, dp, 0, 0 ) ;

    cout << ans << endl ;

}