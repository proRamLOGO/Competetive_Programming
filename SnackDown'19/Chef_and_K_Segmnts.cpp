#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	t++ ;
    while ( --t ) {  
        long int max = 0,n,k;
		cin >> n >> k ;
		long int a[n], b[n] , minj = 0 , maxx = 0 ;
		for (auto i = 0 ; i < n ; ++i ) { 
            cin >> a[i] >> b[i] ; 
            if( a[maxx] < a[i] ) maxx = i ;
            if( b[minj] > b[i] ) minj = i ;
        }

        string bitmask(k, 1);
        bitmask.resize(n, 0);
        do { 
            int ymin=INT16_MAX ,xmax = INT16_MIN;
            cout << "\nNumber is : " ;
            for ( auto i = 0 ; i < n ; ++i ) {
                if( bitmask[i]) cout << 1 ;
                else cout << 0 ; ;
            }
            if ( bitmask[minj] ) ymin = b[minj] ;
            else {
                for (auto i = 0; i < n; ++i) {
                    if ( bitmask[i] && b[i] < ymin ) ymin = b[i] ;
                }
            }
            if ( bitmask[maxx] ) xmax = a[maxx] ;
            else {
                for (auto i = 0; i < n; ++i) {
                    if ( bitmask[i] && a[i] > xmax ) xmax = a[i] ;
                }
            }
            
            ( ymin - xmax > max) ? max = ymin-xmax : 1;

        } while ( prev_permutation( bitmask.begin(), bitmask.end() )) ;

		//cout << max << "\n" ;
	}
	cout << "\n" ;
}