#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

bool cmp( vector< long long int >  x, vector< long long int >  y ) {

    return x[0] >= x[0] ;

}

int main() {

    long long int t ;

    cin >> t ;

    while ( t-- ) {

        long long int n, b, p, q, r ;

        cin >> n >> b ;

        vector< vector < long long int > > v ;
        vector< long long int > x(2) ;

        for ( auto i = 0 ; i < n ; ++i ) {

            cin >> p >> q >> r ;
            if ( r <= b ) {
                
                x[0] = p*q ;
                x[1] = r ;
                v.push_back(x) ;
            }

        }

        if ( v.size() == 0 ) {

            cout << "no tablet\n" ;
            continue ;

        }

        sort( v.begin(), v.end(), cmp ) ;

        cout << v[0][0] << endl ;

    }


}