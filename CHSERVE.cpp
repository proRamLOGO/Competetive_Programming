#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int t ; 
    cin >> t ;

    while ( t-- ) {

        int p1,p2,k ;
        cin >> p1 >> p2 >> k ;

        int val = (p1+p2) % (k*2) ;

        if ( val < k ) {
            cout << "CHEF\n" ;
            continue ;
        }
        else 
            cout << "COOK\n" ;

    }

}