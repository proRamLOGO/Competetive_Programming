#include <iostream>
#include <vector>

using namespace std;

int main() {

    short int t ;
    cin >> t ;
    
    while ( t-- ) {
        
        int n ;
        cin >> n ;
        vector< int > a(n), b(n) ;
        
        for ( auto i = 0 ; i < n ; ++i )
            cin >> a[i] ;
        for ( auto i = 0 ; i < n ; ++i )
            cin >> b[i] ;
        
        int ans = 0 ;
        //cout << '\n' ;
        for ( auto i = 0 ; i < n ; ++i ) {
            int res = a[i]*20 - b[i]*10 ;
            //cout << res << '\n' ;
            ans = max(res,ans) ;
        }
        
        cout << ans << '\n' ;
        
    }
	
	return 0;
}
