#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std; 

bool cmp( vector< int > a , vector< int > b ) {

    if( a[0]+a[1] == b[1]+b[0] ) 
        return a[0] < b[0] ;
    return a[0]+a[1] < b[1]+b[0] ;
} 

bool chk( int x, int y, std::vector< vector < int > >& grid, int val ) {

    if ( x-2 >= 0 && y >= 0 ) {
        if ( grid[x-2][y] == val )
            return false ;
    }
    if ( x+2 >= 0 && y >= 0 ) {
        if ( grid[x+2][y] == val )
            return false ;
    }
    if ( x-1 >= 0 && y+1 >= 0 ) {
        if ( grid[x-1][y+1] == val )
            return false ;
    }
    if ( x+1 >= 0 && y-1 >= 0 ) {
        if ( grid[x+1][y-1] == val )
            return false ;
    }
    if ( x >= 0 && y+2 >= 0 ) {
        if ( grid[x][y+2] == val )
            return false ;
    }
    if ( x >= 0 && y-2 >= 0 ) {
        if ( grid[x][y-2] == val )
            return false ;
    }
    if ( x-1 >= 0 && y-1 >= 0 ) {
        if ( grid[x-1][y-1] == val )
            return false ;
    }
    if ( x+1 >= 0 && y+1 >= 0 ) {
        if ( grid[x+1][y+1] == val )
            return false ;
    } 
    
    return true ;


}

int main() {

    int t ;
    cin >> t ;
    while ( t-- ) {

        int n, m;
        cin >> n >> m ;

        vector < vector < int > > address, grid(n) ;

        for ( auto i = 0 ; i < n ; ++i ) {
            vector < int > g(m) ;
            grid[i] = g ;
            for ( auto y = 0 ; y < m ; ++y ) {
                //cout << grid[i][y] << ' ' ;
                vector< int > v(2) ;
                v[0] = i ;
                v[1] = y ;
                address.push_back(v) ;
                
            }
            //cout << endl ;
        }

        sort( address.begin(), address.end(), cmp ) ; 

        vector< int > stk ;
        stk.push_back(1) ;

        for ( auto i = 0 ; i < n*m ; ++i ) {

            int x = address[i][0] ;
            int y = address[i][1] ;
            int val ;

            cout << "Filling cell ( " << x << " , " << y << " ):\n " ; 

            bool res, ad_need = true ;

            for ( auto j = 0 ; j < stk.size() ; ++j ) {

                val = stk[j] ;
                cout << "   val = " << val << endl ;
                res = chk( x, y, grid, val ) ;
                (res)? cout << "    res = true\n" : cout << "   res = false\n" ; 
                if ( res ) {
                    grid[x][y] = val ;
                    cout << "   As res = true\n     grid["<<x<<"]["<<y<<"] = " << val << endl ;
                    ad_need = false ;
                    cout << "   No addition needed. Breaking froom loop and onto filling next dest.\n\n" ;
                    break ;
                }

            }

            if ( ad_need ) {

                stk.push_back( stk[stk.size()-1] + 1 ) ;
                grid[x][y] = stk[stk.size()-1] ;

            }

        }

        for ( auto i = 0 ; i < n ; ++i ) {

            for ( auto y = 0 ; y < m ; ++y )
                cout << grid[i][y] << ' ' ;
            
            cout << endl ;
        }


    }

}