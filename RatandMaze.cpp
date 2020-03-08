#include<iostream>
#include <vector>

using namespace std; 

int solve( vector< string > arr, vector< vector < int > > &ans, int i, int j ) {
    
    if ( i==0 && j==0  && arr[i][j] == 'O' )
        return 1 ;
    else if ( arr[i][j] == 'X' )
        return 0 ;
    
    else if ( i-1 >= 0 && solve(arr, ans, i-1, j) ) {
        ans[i-1][j] = 1 ;
        return 1 ;
    }
    else if ( j-1 >= 0 && solve(arr, ans, i, j-1) ) {
        ans[i][j-1] = 1 ;
        return 1 ;
    }
    return 0 ;
    
    
}

int main() {
    
    int n, m ;
    cin >> n >> m ;
    vector<int> x(m,0) ;
    vector< vector<int> > ans(n,x) ;

    vector< string > arr(n) ;
    
    for ( auto i = 0 ; i < n ; ++i )
        cin >> arr[i] ;
    
    if ( solve(arr, ans, n-1, m-1) ) {
        ans[n-1][m-1] = 1 ;
        for ( auto i = 0 ; i < n ; ++i ) {
            for ( auto y = 0 ; y < m ; ++y )
                cout << ans[i][y] << ' ' ;
            cout << endl ;
        }
    }
    else 
        cout << -1 << endl ;
    
	return 0;
}