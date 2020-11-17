#include <iostream>
using namespace std;

int main() {
	
	short int t ;
	cin >> t ;
	
	while ( t-- ) {
	    
	    long long unsigned int n, k ;
	    cin >> n >> k ;
	    
	    if ( k==1 || k*k == n )
	        cout << "NO\n" ;
	    else
	        cout << "YES\n" ;
	    
	}
	
	return 0;
}
