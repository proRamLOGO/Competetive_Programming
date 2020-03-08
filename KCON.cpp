#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

bool overlap( int n, int x, int y ) {
    return ( y-n >= x ) ;
}

struct ans {

    int sum,x,y ;

};

ans kadane( int arr[], int n ) {

    int max_sum = 0, curr_sum = 0, x = 0, y = 0 ;

    for ( int i = 0 ; i < n ; ++i ) {
        curr_sum += arr[i] ;
        if ( max_sum < curr_sum ) {
            max_sum = curr_sum ;
            y = i ;
        }
        if ( curr_sum < 0 ) {
            curr_sum = 0 ;
            x = i+1 ;
        }
    }

    ans a ;
    a.sum = max_sum ;
    a.x = x ;
    a.y = y ;

    return a ;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while ( t-- ) {

        int n, k ;
        cin >> n >> k ;
        int arr[n], arr_ext[2*n] ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> arr[i] ;
            arr_ext[i] = arr_ext[n+i] = arr[i] ;
        }
        
        ans kadaneOnExt = kadane(arr_ext, n+n ) ;

        int ans = kadaneOnExt.sum ;
        if ( overlap( n,kadaneOnExt.x,kadaneOnExt.y ) ) {
            ans *= (k/2) ;
            if ( k&1 ) 
                ans += kadane(arr,n).sum ;
        } else {
            ans *= (k-1) ;
        }

        cout << ans << endl ; 

    }

}
