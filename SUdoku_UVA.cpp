#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
#define N 16 

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

char qgrid[16][16] ;
const string alpha = "ABCDEFGHIJKLMNOP" ;

bool fits( int i, int j, char x ) {

    for ( int p = 0 ; p < 16 ; ++p )
        if ( qgrid[p][j] == x or qgrid[i][p] == x )
            return false ;
    
    int r = (i/4)*4, c = (j/4)*4 ;

    for ( int p = r ; p < r+4 ; ++p  )
        for ( int q = c ; q < c+4 ; ++q )
            if ( qgrid[p][q] == x )
                return false ;
    
    return true ;

}

bool solve( int i, int j) {

    // cout << i << ' ' << j << endl ;

    if ( i == 16 ) {
        // cout << "here" << endl ;
        return true;
    }
    else if ( j == 16 ) {
        return solve( i+1, 0 ) ;
    }
    else if ( qgrid[i][j] != '-' ) {
        return solve( i, j+1 ) ;
    }
    else {
        // cout << "Trying for " << i << ' ' << j << endl ;
        for ( int x = 'A' ; x < 'Q' ; ++x ) {
            // cout << "Try" << (char)x << endl ;
            if ( fits( i, j, (char)x  ) ) {
                qgrid[i][j] = (char)x ;
                bool res = solve( i, j+1 ) ;
                if ( res == true ) {
                    // cout << "Returning true" << endl ;
                    return true ;
                } else 
                qgrid[i][j] = '-' ;
            }
        }
        // cout << "Returning false" << endl ;
        return false ;

    }

}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    for ( int i = 0 ; i < N ; ++i )
        for ( int j = 0 ; j < N ; ++j  )
            cin >> qgrid[i][j] ;

    bool res = solve( 0, 0 ) ;

    if ( res ) {
        for ( int i = 0 ; i < 16 ; ++i ) {
            for ( int j = 0 ; j < 16 ; ++j ) 
                cout << qgrid[i][j] << ' ' ;
            cout << endl ;
        }
    } else {
        cout << "Unsolvable" << endl ;
    }


    return 0 ;

}