#include <bits/stdc++.h>

using namespace std ;

vector< vector<int> > grid ;
int ans,r,c,n,m ;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} } ;
int pathlength ;

bool cango(int i, int j) {
    return ( i<n and i>-1 and j<m and j>-1 and grid[i][j] != 1 ) ;
}

void dfs( int i, int j, int cost, vector< vector< bool > > vis, int pl ) {

    if ( i==r and j==c ) {
        ans = max(ans,cost) ;
        pathlength = min(pl,pathlength) ;
        return ;
    }

    for ( int k = 0 ; k < 4 ; ++k ) {
        int x = i + dir[k][0], y = j + dir[k][1] ;
        if ( cango(x,y) and !vis[x][y] ) {
            vis[x][y] = true ;
            dfs(x, y, cost+(grid[i][j]==2), vis, pl+1 ) ;
            vis[x][y] = false ;
        }
    }


}

int32_t main(int argc, char** argv) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif

    cin >> n >> m ;
    
    ans = 0;
    pathlength = 10001 ;

    grid.clear() ;
    grid.resize(n) ;
    fill(grid.begin(),grid.end(),vector<int>(m)) ;

    int totalcoins = 0 ;
    for ( auto &i : grid )
        for ( auto &j : i )
            cin >> j, totalcoins += (j==2) ;

    cin >> r >> c ;
    --r, --c ;

    dfs(0,0,0, vector< vector< bool > > (n, vector< bool >(m,false)) , 0) ;

    cout << ((ans==totalcoins) ? pathlength : -1) << endl ; 

    for ( auto &i : grid ) {
        for ( auto &j : i )
            cout << j << ' ';
        cout << endl ;
    }

    // for ( int i = 0 ; i < 100 ; ++i ) {
    //     for ( int j = 0 ; j < 100 ; ++j )
    //         cout << rand()%3 << ' ' ;
    //     cout << endl ;
    // }


}