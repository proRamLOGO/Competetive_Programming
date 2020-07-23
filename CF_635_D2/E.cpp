#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 998244353
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

short int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101} ;
unordered_map<int,char> dict ;

ll solve( string s, string t, string a, vll &dp, ll idx ) {

    if ( dp[idx]!=-1 )
        return dp[idx] ;

    if ( s.size()==0 ) {
        if (a.compare(t)==0)
            return dp[idx]=1 ;
        else 
            return dp[idx]=0 ;
    }


}



int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    for ( int i = 0 ; i < 26 ; ++i ) {
        dict[primes[i]] = (char)('a'+i) ;
    }

    int t ;
    cin >> t ;

    while ( t-- ) {

        string s,t ;
        cin >> s >> t ;
        vll dp(303000,-1) ;
        solve(s,t,"",dp,1) ;

    }

    return 0 ;
    
}