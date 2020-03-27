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

        int n, mine = 200 ;
        cin >> n ;
        int arr[n] ;

        for ( int i = 0 ; i < n ; ++i ) {
            cin >> arr[i] ;
            mine = min(mine,arr[i]) ;
        }

        bool ans = true ;
        for ( int i = 0 ; i < n ; ++i ) {
            arr[i] -= mine ;
            if ( arr[i]%2 ) {
                ans = false ;
                break ;
            }
        }

        if ( ans ) {
            cout << "YES" << endl ;
        } else {
            cout << "NO" << endl ;
        }

    }

}
