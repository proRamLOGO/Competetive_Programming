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

        int n, m ;
        cin >> n >> m ;

        if ( n%m==0 and m > 2 ) {
            cout << "YES" << endl ;
        } else {
            cout << "NO" << endl ;
        }

    }

}
