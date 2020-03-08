#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define clr(a) memset(a, 0, sizeof(a))
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
  
vll factorial(21,1) ;

void __init_fact( void ) {
    for ( int i = 2 ; i < 21 ; ++i ) {
        factorial[i] = ( (ll)i * factorial[i-1] ) %MOD ;
    }
}

float check_probability( string sent, string rec ) {

    int l_sent = 0, r_sent = 0 ;
    for ( auto i : sent ) {
        if ( i == '+' ) ++r_sent ;
        else ++l_sent ;
    }

    int l_rec = 0, r_rec = 0 ;
    for ( auto i : rec ) {
        if ( i == '+' ) ++r_rec ;
        else if ( i == '-' ) ++l_rec ;
    }

    int qmarks = len(rec)-r_rec-l_rec ;

    if ( qmarks==0 && l_sent == l_rec && r_sent == r_rec )
        return 1 ;
    
    if ( l_rec > l_sent || r_rec > r_sent )
        return 0 ;
    
    ll xf = factorial[qmarks] ;
    ll den = 1ll<<qmarks ;

    float res = (float)xf/(float)den ;
    return res ;

}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    __init_fact() ;

    string sent, rec ;
    cin >> sent >> rec ;

    float probability = check_probability(sent,rec) ;
    printf("%0.9f\n",probability) ;

    return 0 ;

}