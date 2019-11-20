#include <bits/stdc++.h>

using namespace std;

long long int b_search( vector<long long int> arr , long long int ele ) {

    long long int hi = arr.size() ;
    long long int lo = 0 ;
    long long int ans = -1 ;
    long long int mid ;

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

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen("output.txt", "w", stdout) ;
    #endif 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, x ;
    cin >> n >> x ;
    vector< long long int > arr(n) ;
    for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;
    sort(arr.begin(),arr.end()) ;

    long long int y = b_search( arr, x ) ;
    cout << y << " " << arr[y] << endl ;

    return 0;
}
