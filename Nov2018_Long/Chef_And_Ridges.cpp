#include <iostream> 
#include <vector> 

using namespace std; 

long int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    vector< long long int > X(26), p(26) ;
    X[0] = 0 ; p[0] = 1 ;
    X[1] = 1 ; p[1] = 2 ;
    X[2] = 1 ; p[2] = 4 ;
    for ( auto i = 3 ; i < 27 ; ++i ) {
        X[i] = X[i-1] + X[i-2] + X[i-2] ;
        p[i] = ((p[i-1])*2) ;
    }

    long int t ;
    cin >> t ;
    while ( t-- ) {
        long int n ; 
        cin >> n ;
        cout << X[n] << " " << p[n] << " " ; 
    }

    return 0;

}