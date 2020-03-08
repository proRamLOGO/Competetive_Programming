#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

void generate_matrix( int n ) {

    int doof_matrix[n][n] ;

    // L-R Diagonal
    for ( int i = 0 ; i < n ; ++i ) {
        doof_matrix[i][i] = 2*n-1 ;
    }

    // R-L Diagonal 
    for ( int i = 0 ; i < n/2 ; ++i ) {
        doof_matrix[n/2 + i ][n/2 - i - 1] = 2*n - 2 ; // Left Side
        doof_matrix[n/2 - i - 1][n/2 + i ] = n - 1 ; // Right Side
    }

    // Boundaries
    for ( int i = 1 ; i < n-1 ; ++i ) {
        doof_matrix[i][0] = n+i-1 ; // Left
        doof_matrix[0][i] = i ; // Top
    }

    for ( int i = 1 ; i < n-1 ; ++i ) {
        
        //West Block
        int target = doof_matrix[i][0] ;
        int x = i, y = 0 ;
        while ( x > y ) {
            doof_matrix[x][y] = target ;
            --x ; ++y ;
        }

        //North Block
        target = doof_matrix[0][i] ;
        x = 0 ; y = i ;
        while ( x < y ) {
            doof_matrix[x][y] = target ;
            ++x ; --y ;
        }

    }

    for ( int i = 1 ; i < n/2 - 1 ; ++i ) {
        
        // South Block
        for ( int j = 0 ; j < 2*i ; ++j ) {
            doof_matrix[n/2+i][n/2-i+j] = n + j ;
        }

        // East Block
        for ( int j = 0 ; j < 2*i ; ++j ) {
            doof_matrix[n/2-i+j][n/2+i] = 1 + j ;
        }

    }

    for ( int i = n/2 ; i < n-1 ; ++i ) {

        //Bottom Boundary
        doof_matrix[n-1][i] = n + 2*(i - n/2) ;
        doof_matrix[n-1][i-n/2+1] = n + 2*(i - n/2) + 1;
        
        //Right Boundary
        doof_matrix[i][n-1] = 1 + 2*(i - n/2) ;
        doof_matrix[i-n/2+1][n-1] = 1 + 2*(i - n/2) + 1;

    }

    for ( int i = 0 ; i < n ; ++i ) {
        for ( int j = 0 ; j < n ; ++j ) {
            cout << doof_matrix[i][j] << " " ;
        }
        cout << endl ;
    }

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n ;
    cin >> t ;

    while ( t-- ) {

        cin >> n ;

        if ( n==1 ){
            cout << "Hooray\n1" << endl ;
            continue ;
        }
        if ( (n&1) == 1 ) {
            cout << "Boo" << endl ;
            continue ;
        }

        cout << "Hooray" << endl ;
        generate_matrix( n ) ;


    }

}
