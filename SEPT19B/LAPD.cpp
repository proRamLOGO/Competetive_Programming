#include <bits/stdc++.h>
#define M 1000000007
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
    while( t-- ) {

        int B ;
        llui A,C, ans=0 ;
        cin >> A >> B >> C ;
        for ( int i = 2 ; i <= A ; ++i ) {
            for ( int j = 1 ; j <= A && j <= C ; ++j ) {
                for ( int k = 1 ; k <= C ; ++k ) {
                    if ( j  *j < (i-1)*(k-1) ) {
                        ans++ ;
                        ans %= M ;
                        break ;
                    }
                }
            }
        }
        cout << ans << endl ;

    }
}