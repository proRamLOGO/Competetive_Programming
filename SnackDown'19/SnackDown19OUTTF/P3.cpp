#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t;
    cin >> t ;
    while ( t-- ) {
    
        long long int n,days = 0,ans=0;
        cin >> n;
        if(n) {
            vector< long long int > arr(n),sum(n) ;
            for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;
            sum[0] = arr[0] ;
            for ( auto i = 1 ; i < n ; ++i ) {
                sum[i] = sum[i-1] + arr[i] ;
            }
            //for ( auto c : sum ) cout << c << " " ;
            //cout << "\n" ;
            for ( auto i = 0 ; i < n-1 ; ) {
                //cout << "ans = " << ans << " i = " << i << " days = " << days << endl;
                i += sum[i] - 1 ; 
                ++i ;
                days++ ;
                //cout << "ans = " << ans << " i = " << i << " days = " << days << endl << endl;  

            }

            cout << days << endl ;
        }
    
    }

}