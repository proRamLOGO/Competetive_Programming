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

bool checkValidString(string s) {
    
    int o=0, c=0, n=s.size() ;
    for ( int i = 0 ; i < n ; ++i ) {
        if ( s[i]=='(' or s[i]=='*' ) o++ ;
        else --o ;
        if ( s[n-1-i]==')' or s[n-1-i]=='*' ) ++c ;
        else --c ;
        if ( c<0 or o<0 ) return false ;
    }
    return true ;
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
        
        string s ;
        cin >> s;
        cout << checkValidString(s) << endl ;

    }

    return 0 ;

}
