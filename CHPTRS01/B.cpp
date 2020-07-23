#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define left first
#define right second
#define MOD 1000000007d
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

void pq( queue<int> q ) {
    while (!q.empty()) 
        cout << q.front() << ' ' , q.pop() ;
    
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

        int n, d, loc, ans = 0 ;
        string s ;
        cin >> n >> s >> d ;

        vector < pair< bool, bool > > links(n,mp(1,1)) ;
        links[0].left = 0 ;
        links[n-1].right = 0 ;

        queue<int> idx ;
        for ( int i = 0 ; i < n ; ++i )
            if ( s[i]=='1' ) 
                idx.push(i) ;
        idx.push(-1) ;
        
        vector<int> b(d) ;
        for ( int i = 0 ; i < d ; ++i ) {
            cin >> b[i] ;
        }
        
        // pq(idx) ;
        for ( int i = 0 ;  i < d ; ++i ) {
            string ns = s; 
            loc = b[i] ;
            links[loc-1].left = 0 ;
            if ( loc != 1 )
                links[loc-2].right = 0 ;

            while( idx.front() != -1 ) {

                int j = idx.front() ;
                idx.pop() ;
                if ( links[j].left and j-1 >=0 and ns[j-1] != '1' ) {
                    ns[j-1] = '1' ;
                    idx.push(j-1) ;
                }
                if ( links[j].right and j+1 <n and ns[j+1] != '1' ) {
                    ns[j+1] = '1' ;
                    idx.push(j+1) ;
                }

            }
            
            idx.pop() ;
            idx.push(-1) ;
            
            // pq(idx) ;

            if ( idx.size() == 1 ) {
                break ;
            }

            s = ns ;

        }

        for ( auto i : s )
            ans += (i-'0') ;

        cout << ans << endl ;

    }

    return 0 ;
    
}