#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define x first
#define y second
#define MOD 1000000007d
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

void pq( queue<int> q ) {
    while (!q.empty()) 
        cout << q.front() << ' ' , q.pop() ;
    
}

int cntsetbits( ull n ) {
    int cnt = 0 ;
    while ( n != 0 ) {
        ++cnt ;
        n &= (n-1) ;
    }
    return cnt ;
}

ull rb( ull n ) {
    ull cnt = 0;
    while ( n!=0 ) {
        cnt++ ;
        n >>= 1 ;
    }
    return cnt ;
}

ull rr( ull n ) {
    ull p = rb(n) ;
    ull z=(n&1) ;
    n >>= 1 ;
    n |= (z<<p) ;
    return n ;
}

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t ;
    cin >> t ;
    
    while ( t-- ) {

        int m, n, x0 = -1, y0 = -1, xl = -1 ;
        cin >> m >> n ;
        char parking[m][n] ;
        vector< pair < int, int > > extremes(m,mp(-1,-1)) ;

        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                cin >> parking[i][j] ;
                if ( parking[i][j] == 'P' ) {
                    xl = i ;
                    if ( x0 == -1 ) {
                        x0 = i; y0 = j ;
                    }
                    if ( extremes[i].x == -1 )
                        extremes[i].x = j ;
                    extremes[i].y = j ;
                } 
            }
        }
        
        // if ( x0 == -1 ) {
        //     cout << 0 << endl ;
        //     continue ;
        // }

        int pos = y0 ;

        int moves = 0 ;
        for ( int i = x0 ; i < xl ; ++i ) {
            // left on odd, roght on eve
            // cout << i << "  :  " ;
            if ( i & 1 ) {
                if ( extremes[i].x >= 0 and extremes[i+1].x >= 0 )
                    y0 = min( extremes[i].x, extremes[i+1].x ) ;
                else if ( (extremes[i].x)*(extremes[i+1].x) < 0 ) {
                    y0 = max( extremes[i].x, extremes[i+1].x ) ;
                } else {
                    ++moves ;
                    continue ; 
                }
                // cout << y0 << ' ' << pos-y0 << endl ;
                moves += pos-y0 ;
            } else {
                if ( extremes[i].y > -1 or extremes[i+1].y > -1 ) {
                    y0 = max( extremes[i].y, extremes[i+1].y ) ;
                } else {
                    ++moves ;
                    continue ; 
                }
                // cout << y0 << ' ' << y0-pos << endl ;
                moves += y0-pos ;
            }
            pos = y0 ;
            // cout << "moves inc " << moves << endl ;
            ++moves ;
        }

        if ( (xl+1) & 1 ) {
            y0 = max(y0,extremes[m-1].y) ;
            // cout << y0 << ' ' << y0-pos << endl ;
            moves += y0-pos ;
        } else {
            // y0 = min( max(extremes[m-1].x,y0) extremes[i+1].x ) ;
            if ( extremes[m-1].x > -1 )
                y0 = min( extremes[m-1].x, y0 ) ;
            // cout << y0 << ' ' << pos-y0 << endl ;
            moves += pos-y0 ;
        }
        
        
        // cout << "moves inc " << moves << endl ;
        cout << moves << endl ;

    }

    return 0 ;
    
}