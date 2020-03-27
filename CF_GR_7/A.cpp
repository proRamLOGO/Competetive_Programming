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

        int n ;
        cin >> n ;

        if ( n==1 ) {
            cout << -1 << endl ;
        } else if ( n==2 ) {
            cout << 57 << endl ;
        } else if ( n==3 ) {
            cout << 239 << endl ;
        } else {
            string ans = string(n-1,'3')+"4" ;
            cout << ans << endl ;
        }

    }

}
