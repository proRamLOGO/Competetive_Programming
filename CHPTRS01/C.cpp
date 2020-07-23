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

        ull a,b ;
        cin >> a >> b ;

        ull z=1, sb=(ull)cntsetbits(b) ;
        ull limit = z<<(sb) ;
        limit--;

        ull mv = a^b ;
        int mi = 0 , cnt = 0 ;

        while ( b != limit ) {
            ++cnt ;
            b = rr(b) ;
            if ( (a^b) > mv ) {
                mv = a^b ;
                mi = cnt ;
            }
        }

        cout << mi << ' ' << mv << endl ;

    }

    return 0 ;
    
}