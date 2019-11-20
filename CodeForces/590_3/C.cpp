#include <bits/stdc++.h>

#define lui long unsigned int 
#define llui long long unsigned int 
#define max = 200000
using namespace std ;

int path[7] = { 0,  }

bool pathit( char *net[2] , char *res[2], int i, int j, int n ) {

    // Base Case

    if ( net[i][j] < 3 ) {

        bool r = pathit( net, res, i, j+1, n ) ;
        if ( !r ) {
            bool d = pathit( net, res, i+1, j, n ) ;
            return d ;
        }
        return true ;

    }

    if ( net[i][j] > 2 ) {

        bool r = pathit( net, res, i, j+1, n ) ;
        if ( !r ) {
            bool d = pathit( net, res, i+1, j, n ) ;
            return d ;
        }
    }

}


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q ;
    cin >> q ;

    while ( q-- ) {

        int n ;
        char net[2][n], res[2][n] ;
        cin >> net[0] >> net[1] ;



    }

}