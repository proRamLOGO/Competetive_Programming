#include <bits/stdc++.h> 
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
typedef unsigned long long int ulli;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

ll fact( int x ) {
    ll res = x ;
    for ( int i = 2 ; i < x ; ++i )
        res *= i ;
    return res ;
}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n, k1, k2, x ;
    cin >> n ;

    queue<int> q1, q2 ;

    cin >> k1 ;
    for ( int i = 0 ; i < k1 ; ++i ) 
        cin >> x, q1.push(x) ;
    
    cin >> k2 ;
    for ( int i = 0 ; i < k2 ; ++i ) 
        cin >> x, q2.push(x) ;
    
    ll limit = 107 ;

    ll i ;
    for ( i = 0 ; q1.size() > 0 and q2.size() > 0 and i < limit ; ++i ) {

        int p1 = q1.front() ;
        int p2 = q2.front() ;
        q1.pop() ; q2.pop() ;
        if ( p1 > p2 ) {
            q1.push(p2) ;
            q1.push(p1) ;
        } else {
            q2.push(p1) ;
            q2.push(p2) ;
        }

        // cout << q1.size() << ' ' << q2.size() << endl  ;

    }

    if ( i == limit ) 
        cout << -1 << endl ;
    else 
        cout << i << ((q1.size()!=0) ? " 1" : " 2") << endl ; 


    return 0 ;

}
