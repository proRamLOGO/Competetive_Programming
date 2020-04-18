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

int sqrit( int n ) {
    int res = 0 ;
    while ( n != 0 ) {
        res += (n%10) * (n%10) ;
        n/=10 ;
    }
    return res; 
}

bool isHappy(int n) {
    
    int slow, fast ;
    slow = fast = n ;
    
    do {
        slow = sqrit(slow) ;
        fast = sqrit(sqrit(fast)) ;
        // n = slow ;
    } while ( slow != fast ) ;
    
    return ( slow==1 ) ;
        
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
        
        int n;
        cin >> n ;
        cout << isHappy(n);

    }

    return 0 ;

}
