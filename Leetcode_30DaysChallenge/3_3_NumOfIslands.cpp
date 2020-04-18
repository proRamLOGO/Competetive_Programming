#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

class disjointset {
public:
    vector<long long int> parent, size ;
    long long int n,m ;
    disjointset(long long int n, long long int m, vector< vector< char > > grid ) {
        this->n = n ;
        this->m = m ;
        this->parent.resize(n*m) ;
        this->size.resize(n*m,1) ;
        for ( long long int i = 0 ; i < n ; ++i ) {
            for ( long long int j = 0 ; j < m ; ++j ) {
                this->parent[i*m + j] = (grid[i][j]=='0') ? -1 : ((i*m) + j) ;
                this->size[i*m + j] = (grid[i][j]=='0') ? -1 : 1 ;
            }
        }
    }
    
    long long int root( long long int x ) {
        while ( this->parent[x] != x ) {
            this->parent[x] = this->parent[this->parent[x]] ;
            x = this->parent[x] ;
            
        }
        return x ;
    }
    
    void unionit( long long int x, long long int y ) {
        
        long long int px = this->root(x) ;
        long long int py = this->root(y) ;
        
        this->parent[py] = px ;
        this->size[px]++ ;
    }
                                           
    void perfectparent() {
        for ( long long int i = 0 ; i < n*m ; ++i ) {
            if ( this->parent[i] != -1 )
                this->parent[i] = this->root(i) ;
        }
    }
                                           
    long long int distinctparents() {
        unordered_set<long long int> dp ;
        for ( long long int i = 0 ; i < this->n * this->m ; ++i ) {
            if ( this->parent[i] == -1 )
                continue ;
            dp.insert( this->parent[i] ) ;
        }
        return dp.size() ;
    }
    
};

int numIslands(vector < vector<char > >& grid) {
    
    long long int n = grid.size() ; if ( n==0 ) return 0 ;
    long long int m = grid[0].size() ; if ( m==0 ) return 0 ;
    
    disjointset djs(n,m,grid) ;
    

    for ( long long int i = 0 ; i < n ; ++i ) {
        for ( long long int j = 0 ; j < m ; ++j ) {
            if ( grid[i][j] == '1' ) {
                if ( i>0 and grid[i-1][j]=='1' ) {
                    djs.unionit( i*m+j, (i-1)*m+j ) ;
                }
                if ( j>0 and grid[i][j-1]=='1' ) {
                    djs.unionit( i*m+j, i*m+(j-1) ) ;
                }
            }
        }
    }

    djs.perfectparent() ;

    return djs.distinctparents() ;
    
}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t=1 ;
    // cin >> t ;

    while( t-- ) {
        
        int n, m ;
        cin >> n >> m ;
        vector< vector< char > > grid(n,vector<char>(m)) ; 
        for ( int i = 0 ; i < n ; ++i )
            for ( int j = 0 ; j < m ; ++j )
                cin >> grid[i][j] ; 
        
        cout << numIslands(grid) ;

    }

    return 0 ;

}
