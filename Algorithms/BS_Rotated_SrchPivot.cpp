#include <iostream>
#include <vector>

using namespace std ;

int main() {

    int n, x ;
    cin >> n ;

    vector< int > v(n) ;

    for ( auto i = 0 ; i < n ; ++i ) 
        cin >> v[i] ;
    cin >> x ;

    int lo = 0, hi = n-1, mid, ans=-1 ;
    
    //Binary Search

    while ( hi >= lo ) {

        mid = (hi+lo) / 2 ;

        if ( v[mid]==x ) {
            ans = mid ;
            break ;
        }
        
        if ( v[mid] >= v[0]) {
            if ( v[0] <= x <= v[mid] ) 
                hi = mid-1 ;
            else 
                lo = mid+1 ;
        }
        else {
            if ( v[mid] <= x <= v[n-1] ) 
                lo = mid+1 ;
            else 
                hi = mid-1 ;
        }

    }

    cout << "Found " << x << " at " << ans << " index\n\n." ;

    //Find Pivot
    /*
    while ( hi >= lo ) {

        mid = (hi+lo) / 2 ;

        if ( v[mid] > v[mid+1] && mid < hi ) {
            break ;
        }
        else if ( v[mid-1] > v[mid] && mid > lo ) {
            --mid ;
            break ;
        }
        else if ( v[mid] <= v[lo] ) {
            hi = mid-1 ;
        }
        else if ( v[mid] >= v[hi] ) {
            lo = mid+1 ;
        }

    }

    cout << "Pivot at " << mid << " index\n\n" ;*/

}
