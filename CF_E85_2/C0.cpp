#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define hl first
#define im second
#define MOD 1000000007 
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a,n) a, a + n
   
using namespace std; 
  
typedef unsigned long long int ull;
typedef vector<ull> vll;

bool cmp( tuple<ull,ull,int> t1, tuple<ull,ull,int> t2 ) {

    if ( get<0>(t1) == get<0>(t2) ) {
        return (get<1>(t1) >= get<1>(t2)) ;
    }
    return (get<0>(t1) < get<0>(t2)) ;
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
    
    while (t--) {
        
        int n, m=0 ;
        cin >> n ;
        vector< tuple<ull,ull,int> > v(n) ;
        
        for ( int i = 0 ; i < n ; ++i ) {
            ull x, y ;
            cin >> x >> y ;
            v[i] = make_tuple(x,y,i) ;
        }

        vector< tuple<ull,ull,int> > vc = v ;
        sort(allv(vc),cmp) ;
            
        int start = get<2>(vc[0]) ;
        int ans = get<0>(v[start]);

        for ( int i = 1 ; i < n ; ++i ) {
            int idxc = (start+i)%n ;
            int idxp = (start+i-1)%n ;
            int damage = 0ull ;
            if ( get<0>(v[idxc]) > get<1>(v[idxp]) ) {

                damage += ( get<0>(v[idxc]) - get<1>(v[idxp]) ) ;
            }
            // cout <<idxc << ' '<< damage << endl ;

            ans += damage ;
        }

        cout << ans << endl ;

    }	
    
	return 0;
}
