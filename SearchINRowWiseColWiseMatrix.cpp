#include <bits/stdc++.h>

using namespace std ; 

int main() {

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen( "output.txt", "w", stdout ) ;
    #endif

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n, x ;
    cin >> n ;

    int matrix[n][n] ;

    for ( auto i : matrix ) 
        for ( auto j = 0 ; j < n ; ++j )
            cin >>  i[j] ;

    cin >> x ;

    /* // Printing MAtrix
    cout << endl ;
    for ( auto i : matrix ) {
        for ( auto j = 0 ; j < n ; ++j )
            cout << i[j] << ' ' ;
        cout << endl ;
    } */

    int i = 0, j = n-1, posx = -1, posy = -1 ;
    while ( i < n && j > -1 ) {

        if ( matrix[i][j] == x ) {
            posx = i ; posy = j ;
            break ;
        }
        else if ( matrix[i][j] < x )
            ++i ;
        else 
            --j ;

    }
    cout << posx << ' ' << posy << endl ;
    

}

