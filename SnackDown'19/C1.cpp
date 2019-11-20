#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

	int t;
	cin >> t;
	
    while ( t-- ) {  
	
        long int max = 0 ;
		long int n, k, x, y ;
		cin >> n >> k ;
		set<long int> a, b;
		for (auto i = 0 ; i < n ; ++i )  cin >> x >> y ;
		string bitmask(k, 1);
        bitmask.resize(n, 0);
        do { 
        int ymin=100000000,xmax = 0;
       
        for (auto i = 0; i < n; ++i) {
            if (bitmask[i]) 
            { 
			( a[i] > xmax ) ? xmax = a[i] : 1 ;
            ( b[i] < ymin ) ? ymin = b[i] : 1 ;
			}
            
        }
        ( ymin - xmax > max) ? max = ymin-xmax : 1;

    } while (prev_permutation(bitmask.begin(), bitmask.end()));

		cout << max << endl ;
	}
	return 0;
}