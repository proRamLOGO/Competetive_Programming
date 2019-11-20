#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	int n, k, cmax ;
	cin >> n ;
	vector< int > v(n) ;
	for ( auto i = 0 ; i < n ; ++i )
		cin >> v[i] ;
	cin >> k ;
	cmax = v[0] ;

	for ( auto i = 0 ; i < n ; ++i ) {
		( cmax < v[i] )? cmax = v[i] : 1 ;
		if( i >= k-1 )
            cout << cmax << ' ' ;
	}
	
	return 0;
}