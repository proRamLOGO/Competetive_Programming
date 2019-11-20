#include <iostream>
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

        llui s, i, e ;
        cin >> s >> i >> e ;
        if ( !e )
            cout << 1 << "\n" ;
        else if ( s > i ) 
            cout << e-1 << "\n" ;
        else {
            llui n = i-s ;
            if ( e <= n ) 
                cout << 0 << "\n" ;
            else 
                cout << e-n-1 << "\n" ;

        }

    }
    cout << endl ;

}