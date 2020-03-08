#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcAns( vector<int>& v, int n, int x) {

    if ( n == 0 )
        return 0 ;
    
    int m = INT_MIN ;

    for ( auto i = 0 ; i < x ; ++i ) {
        int res = 0 ;
        if ( v[i] <= n ) {
            cout << "\nReducing " << v[i] << " from " << n ;
            res = 1 + calcAns( v, n-v[i], x ) ;
            cout << "\nReturned from rec\n" ;
            //break ;
        }
        m = max( res, m ) ;
    }
    cout << "\nm =" << m ;    
    return m ;
}

int main() {
	
	int n, x ;
	cin >> n >> x ;
	
	vector< int > v(x) ;
	
	for ( auto i = 0 ; i < x ; ++i )
	    cin >> v[i] ;
	   
	sort( v.begin(), v.end() ) ;
	
	cout <<  calcAns( v, n, x ) << endl ;
	
	return 0;
}
