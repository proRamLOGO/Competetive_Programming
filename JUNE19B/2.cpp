#include <iostream>
#include <math.h>
#include <vector>

using namespace std ;

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        int n ;
        cin >> n ;
        long long int res = 19 + (n-1)*9 ;
        long long int rem = log10(res) - 1 ;
        res += 9*rem ;
        cout << res << endl ;

    }

}