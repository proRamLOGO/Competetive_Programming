#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

long int b_search( vector<long int> arr , long int ele ) {

    long int hi = arr.size()-1 ;
    long int lo = 0 ;
    long int ans = -1 ;
    long int mid ;

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

bool cmp1( vector< long int > x, vector< long int > y ) {

    if ( x[0] < y[0] ) return true ;
    else return false ;

}

bool cmp2( vector< long int > x, vector< long int > y ) {

    if ( x[1] < y[1] ) return true ;
    else return false ;

}

int main() {

    long int n, x, y ;
    cin >> n >> x >> y ;
    vector< vector< long int > > dur(n, vector< long int > (2)) ;
    for ( auto i = 0 ; i < n ; ++i ) cin >> dur[i][0]>> dur[i][1] ;
    
    vector< long int > v(x), w(y) ;
    for ( auto i = 0 ; i < x ; ++i ) cin >> v[i] ;
    for ( auto i = 0 ; i < y ; ++i ) cin >> w[i] ;

    sort( v.begin(), v.end() ) ;
    sort( w.begin(), w.end() ) ;
    sort( dur.begin(), dur.end(), cmp1 ) ;

    long int ans = INT16_MAX ;

    for ( auto i = 0 ; i < n ; ++i ) { 
        
        long int t1 = b_search( v, dur[i][0] ) ;
        long int t2 = b_search( w, dur[i][1] ) ;

        if ( t1 == -1 || t2 == -1 ) continue ;
        //if ( t1 != 0 ) --t1 ;
        if ( w[t2] <= v[t1] ) continue ;

        long int res = w[t2] - v[t1] + 1 ;

        if ( res < ans ) ans = res ; 

    }

    cout << ans << endl  ;



}