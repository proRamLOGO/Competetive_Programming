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

        llui n, k ;
        cin >> n >> k ;

        llui sum = (k*(k+1))/2 ;

        if ( (n+k)%2 == 0 ) {
            n = (n+k)/2 ;
            if ( n >= sum ) {
                cout << "YES" << endl ;
            } else {
                cout << "NO" << endl ;
            }
        } else {
            cout << "NO" << endl ;
        }

    }

}
