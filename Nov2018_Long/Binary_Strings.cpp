#include <iostream> 
#include <vector> 
#include <bitset>

using namespace std; 

long int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    long int n, q ;
    cin >> n >> q ;
    vector< bitset<16> > arr(n), quer(q+1) ;
    for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;

    for ( auto i = 0 ; i < q ; ++i ) {

        long int l, r, ans ;
        quer[q] = 0 ;
        cin >> l >> r >> quer[i] ;
        for ( auto y = l-1 ; y < r ; ++y ) {

            if ( (arr[y]^quer[i]).to_ulong() > quer[q].to_ulong() ) {
                quer[q] = arr[y]^quer[i] ;
                ans = y+1 ;
            }
        }

        cout << ans << endl ;

    }

}