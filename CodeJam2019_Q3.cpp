#include <bits/stdc++.h>
#define lli long unsigned int 

using namespace std ;

int  main() {
    
    lli  T ;
    cin >> T ;

    for ( auto t = 0 ; t < T ; ++t ) {

        lli  n, X ;
        bool f = 0 ;
        cin >> X >> n ;
        vector< lli > print, v(n)  ;
        set< lli  > vals ;
        lli  x, y ;

        cin >> v[0] ;
        for ( auto i = 1 ; i < n ; ++i ) {
            cin >> v[i] ;
            if ( v[i-1] != v[i] && !f ) {
                f = 1 ;
                X = __gcd(v[i-1], v[i] ) ;
                y = X ;
                x = v[i-1] / y ;
            }
        }
        
        print.push_back(x) ;
        vals.insert(x) ;
        for ( auto i = 0 ; i < n ; ++i ) {
            X = v[i]/x ;
            print.push_back(X) ;
            vals.insert(X) ;
            x = X ;
        }
        unordered_map<lli ,char> dict ;

        string pan = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

        int cnt = 0 ;
        for ( auto c : vals ) {
            dict[c] = pan[cnt] ;
            ++cnt ;
        }

        cout << "Case #" << t+1 << ": " ;

        for ( auto i : print ) 
            cout << dict[i] ;

        cout << endl ;
    }
}