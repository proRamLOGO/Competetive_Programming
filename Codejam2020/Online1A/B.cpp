#include <bits/stdc++.h>
#define pb push_back
#define llui long long unsigned int
using namespace std ;

int main() {
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin) ;
    // freopen("output.txt","w",stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t ;
    cin >> t ;
    
    for ( int T = 1 ; T <= t ; ++T ) {
        
        int n ; 
        cin >> n ;
        
        cout << "Case #" << T << ":\n" ;

        cout << "1 1" << endl ;
        if ( n>1 )
            cout << "2 1" << endl ;
        if ( n>2 )
            cout << "2 2" << endl ;
        for ( int i = 2 ; i < n-1  ; ++i ) {
            cout << i+1 << ' ' << i+1 <<endl ;
        }


    }
    
}