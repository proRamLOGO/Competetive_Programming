#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        int v1, v2, v3, t1, t2, t3 ;
        cin >> v1 >> t1 >> v2 >> t2 >> v3 >> t3 ;

        bool ans = 0 ;

        for ( auto v = v3 ; v <= v1+v2 && !ans ; ++v ) {

            for ( auto i = v ; i >= 0 ; --i ) {

                if ( i*t1 + (v-i)*t2 == t3*v && ( i <= v1 && v-i <= v2 )  ) {
                    ans = 1 ;
                    cout << endl << i << ' ' << v-i << endl ;
                    break ;
                }

            }

        }

        ( ans )? cout << "YES\n" : cout << "NO\n"  ;

    }

}