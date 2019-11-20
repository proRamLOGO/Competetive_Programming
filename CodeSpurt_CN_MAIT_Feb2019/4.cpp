#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n ;
    cin >> n ;

    vector< int > v(n), freq(2001, 0) ;


    for (auto i = 0 ; i < n ; ++i ) { 
        cin >> v[i] ;
        ++freq[ 1000 + v[i]] ;
    }

    float x = n ;

    for ( auto c : freq ) {

        if ( (c/x)*100 >= 51 ) {
            //cout <<  (c/x)*100 << endl ;  
            cout << "Banal\n" ;
            return 0 ;
        }

    }
    cout << "Interesting\n" ;


    

}
