#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

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

        llui n, d ;
        cin >> n >> d ;
        bool found = false ;

        if ( n >= d ) {
            cout << "YES" << endl ;
            continue ;
        }

        llui lo = 1, hi = n-1 ;

        while ( hi >= lo ) {

            llui mid = (lo+hi)/2 ;

            llui fraction  = d / (mid+1) ;
            if ( fraction*(mid+1) < d )
                ++fraction ;

            llui new_req =  mid + fraction ;

            if ( n >= new_req ) {
                found = true ;
                break ; 
            } else {
                lo = mid+1 ;
            }

        }

        if ( found ) {
            cout << "YES" << endl ;
        } else {
            cout << "NO" << endl ;
        }


    }

}
