#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;



long int main() {

    long int n, sum1 = 0, sum2 = 0;
    cin >> n ; 
    vector< long int > arr(n), res1(n), res2(n) ;

    for ( auto i = 0 ; i < n ; ++i ) 
        cin >> arr[i] ;

    res1[0] = arr[0] ;
    res1[1] = arr[0] + arr[1] ;
    res1[2] = arr[0] + arr[2] ;

    for ( auto i = 3 ; i < n ; ++i ) 
        res1[i] = arr[i] + min( res1[i-1] , res1[i-2] ) ;

    res2[0] = arr[0] ;
    res2[1] = arr[1] ;

    for ( auto i = 2 ; i < n ; ++i ) 
        res2[i] = arr[i] + min( res2[i-1] , res2[i-2] ) ;

    cout << min(res1[n-1],res2[n-1]) << endl ;
}