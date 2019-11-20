#include <iostream>
#include <vector>
#include <algorithm> 
#include <string> 

using namespace std;

int main() {
    
    int t;
    cin >> t ;
    while( t-- ) {
        
        int n;
        cin >> n;
        vector< string > v(n), left(2), right(2) ;
        left[0] = "d" ; left[1] = "f" ; 
        right[0] = "j" ; right[1] = "k" ; 
        cout << endl ;
        for ( auto c : left ) cout << c <<" " ;
        cout << endl ;
        for ( auto c : right ) cout << c <<" " ;
        for ( auto i = 0 ; i < n ; ++i ) cin >> v[i] ;
        




    
    }


}