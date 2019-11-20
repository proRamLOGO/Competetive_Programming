#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std; 

long int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    long int t ;
    cin >> t ;
    while ( t-- ) {

        long int n;
        bool flag = 0 ;
        cin >> n ;
        vector<long int> arr(n), f ;
        vector< vector < long int > > freq(n+1) ;
        
        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> arr[i] ;
            freq[arr[i]].push_back(i+1) ;
        }

        for ( auto i = 1 ; i <= n ; ++i ) {

            if ( freq[i].size() > 1) {
                long int count = 0 ;
                for ( auto y = 0 ; y < freq[i].size() ; ++y ) {

                    ( freq[freq[i][y]].size() > 0 ) ? count++ : 1 ;  
                    if ( count == 2 ) {
                        flag = 1 ;
                        break ;
                    }
                    
                }
            }

            if ( flag ) break ;

        }

        if ( flag ) cout << "Truly Happy\n" ;
        else cout << "Poor Chef\n" ; 

    }

}