#include <iostream> 
#include <vector>
#include <algorithm> 

using namespace std; 

int main() {

    int t;
    cin >> t ;
    while( t-- ) {

        int n,k;
        cin >> n >> k ;
        long long int sum1=0,sum2=0;
        vector< int > v(n) ;
        for ( auto i = 0 ; i < n ; ++i ) cin >> v[i] ;
        sort(v.begin(),v.end());

        for( auto i = 0 ; i < n-k ; ++i ) {

            sum1 += v[i] ;
            sum2 += v[i]*v[i] ;

        }

        if ( sum1 >= sum2 ) cout << "YES\n" ;
        else cout << "NO\n" ;

    }

}