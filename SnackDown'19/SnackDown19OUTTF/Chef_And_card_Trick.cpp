#include <iostream>
#include <vector>
using namespace std;

int main() {

    int t;
    cin >> t ;
    while( t-- ) {

        int n;
        bool flag = 1 ;
        cin >> n;
        vector<int> arr(n) ;
        for( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;
        arr.push_back(arr[0]) ;
        int lo = arr[0] ;
        int moves = 0;
        for( auto i = 1 ; i <= n ; ++i ) {
            if ( arr[i] < arr[i-1] ) {
                moves++;
                if ( moves > 1 ) {
                    flag = 0 ;
                    break ;
                }
            }
        }
        if( flag ) cout << "YES\n" ;
        else cout << "NO\n" ;

    }

}