#include <bits/stdc++.h>
#define lli long long int 

using namespace std ;
 
int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1 ;

    while ( t-- ) {

        int n ;
        cin >> n ;
        lli arr[n] ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> arr[i] ;
        }

        lli sum = 0 ;

        for ( int i = 0 ; i < n ; ++i ) {
            if ( arr[i] < 0 ) 
                cout << abs(sum+arr[i]) << " " ;
            else {
                sum += arr[i] ;
                cout << sum << ' ' ;
            }
        }

        cout << endl ;

    }

}
