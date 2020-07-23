#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define heit first
#define chid second
#define MOD 998244353
#define clr(a) memset(a, 0, sizeof(a)) 
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin()+1, v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

vector<vector<int> > graph ;
vector< tuple<int,int,int> > hc ;
// i, height, children
vector<bool> type ;
vector<int> loc ;

bool cmp2( tuple<int,int,int> t1, tuple<int,int,int> t2 ) {
    if ( get<1>(t1)==get<1>(t2) ) {
        return ((get<2>(t1)) <= (get<2>(t2))) ;
    } else return ((get<1>(t1)) > (get<1>(t2))) ;
}

bool cmp1( tuple<int,int,int> t1, tuple<int,int,int> t2 ) {
    cout << get<0>(t1) << ' ' << get<1>(t1) << ' ' << get<2>(t1) << endl ;
    cout << get<0>(t2) << ' ' << get<1>(t2) << ' ' << get<2>(t2) ;
    if ( get<2>(t1)==get<2>(t2) ) {
        cout << "used 1" << endl ;
        return ((get<1>(t1)) >= (get<1>(t2))) ;
    }
    cout << "used 2" << endl<<endl ;
    return ((get<2>(t1)) <= (get<2>(t2))) ;
}

int findhc(int p, int h) {

    hc[p] = make_tuple(p,h,0) ;
    for ( auto i : graph[p] ) {
        get<2>(hc[p]) += findhc(i,h+1) ;
    }
    return get<2>(hc[p])+1 ;

}

void dfs( int p, int predev, int *ans ) {

    // if p is a dev city add its contri
    if ( type[p]==false ) {
        cout << "Adding contri of " << p << " which is : " << get<1>(hc[loc[p]]) << "  -  " <<  predev  << endl  ;
        *ans += get<1>(hc[loc[p]]) - predev ;
        ++predev ;
    }

    for ( auto i : graph[p] ) {
        dfs(i,predev,ans) ;
    }


}

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t=1 ;
    // cin >> t ;

    while ( t-- ) {

        int n,k ;
        cin >> n >> k ;
        graph.resize(n+1,vector<int>()) ;
        hc.resize(n+1) ;
        type.resize(n+1,true) ;
        loc.resize(n+1,1) ;
        //false->dev , true->tour 
        for ( int i = 0 ; i < n-1 ; ++i ) {
            int u,v ;
            cin >> u >> v ;
            graph[u].pb(v) ; // add edge
            loc[v] = v ;
        }
        
        findhc(1,0) ;
        
        for (  auto i = 1 ; i < 1+n ; ++i ) 
            cout << get<0>(hc[i]) << ' ' << get<1>(hc[i]) << ' ' << get<2>(hc[i]) << '\n'  ;

        sort( allv(hc), cmp1 ) ;
        // sort( allv(hc), cmp2 ) ;

    cout << endl << "\nAfterSort\n\n" ;
        for (  auto i = 1 ; i < 1+n ; ++i ) 
            cout << get<0>(hc[i]) << ' ' << get<1>(hc[i]) << ' ' << get<2>(hc[i]) << '\n'  ;

        for ( int i = 1 ; i <= n ; ++i ) {
            loc[get<0>(hc[i])] = i ;
        }

        for ( int i = 1 ; i <= k ; ++i ) {
            type[get<0>(hc[i])] = false ;
            // cout << "Made false " << (get<0>(hc[i])) << endl ;
        }

        int ans = 0 ;
        dfs(1,0,&ans) ;
        cout << ans << endl ;

    }

    return 0 ;
    
}