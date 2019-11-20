#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    long long int n, q, x, j; 
    cin >> n >> q ;
    vector< long long int > v(n), b(n) ;
    vector< vector< long long int > > ans(n) ;
    for ( auto i = 0 ; i < n ; ++i ) cin >> v[i] ;
    ans[0] = v ;
    for ( auto i = 1 ; i < n ; ++i ) {

        for ( auto y = 0 ; y < n-1 ; ++y ) b[y] = ans[i-1][y] ^ ans[i-1][y+1] ;
        b[n-1] = v[n-1] ;
        ans[i] = b ;

    }
    int c = -1 ;
    for ( auto i : ans ) {
        c++ ;
        cout << "k = " << c << "  :  ";
        for ( auto y : i ) cout << y << " " ;
        cout << "\n" ;
    }


    for ( auto i = 0 ; i < q ; ++i ) {
        cin >> x >> j  ;
        cout << ans[x][j-1] << endl ;
    }

}