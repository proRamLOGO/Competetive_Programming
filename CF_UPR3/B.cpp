#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first 
#define sc second
#define MOD 1000000007
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

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t =1;
    // cin >> t ;

    while ( t-- ) {

        int n, ans=0 ;
        cin >> n ;
        vll v(n) ;
        map<ll,int> freq;
        for ( int i = 0 ; i < n ; ++i ) cin >> v[i], ++freq[v[i]] ;

        for ( auto i : freq ) {
            ll n1 = i.first ;

            for ( int i = 0 ; i < 32 ; ++i ) {
                ll z = 1 ;
                ll sum = z<<i ;
                ll n2 = sum-n1 ;
                cout << n1 << " " << n2 << " " << sum << endl ;
                if ( n2 < n1 )
                    continue ;
                if ( n1 == n2 ) {
                    ans += (freq[n1]*(freq[n1]-1))/2 ;
                }
                else if ( freq.find(n2)!=freq.end() ) 
                    ans += min(freq[n1],freq[n2]) ;

            }

        }
        
        cout << ans << endl ;

    }

    return 0 ;
    
}