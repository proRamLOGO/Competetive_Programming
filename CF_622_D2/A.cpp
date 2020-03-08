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
 
typedef long long ll;
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

    int arr[] = {1,2,3,4,5,6,7} ;
    
    int t ;
    cin >> t ;

    while ( t-- ) {

        int a0, b0, c0 ;
        cin >> a0 >> b0 >> c0 ;
        int ans = 0, cnt = 0 ;
        vector<int> permuter(7) ;
        for ( int i = 0 ; i < 7 ; ++i ) 
            permuter[i] = i ;

        do {

            cnt = 0 ;
            int a=a0, b=b0, c=c0 ;
            for ( int j = 0 ; j <= 6 ; ++j ) {

                int i = arr[permuter[j]] ;
                bool A = (i>>2)&1 ;
                bool B = (i>>1)&1 ;
                bool C = i&1 ;
                
                if ( (A and a<1) or (B and b<1) or (C and c<1) )
                    continue ;

                // cout << A << B << C << endl ;

                if ( A ) {
                    --a ;
                }
                if ( B ) {
                    --b ;
                }
                if ( C ) {
                    --c ;
                } 

                ++cnt ;

            }

            ans = max(ans,cnt) ;

        } while( next_permutation(permuter.begin(),permuter.end()) ) ;


        
        cout << ans << endl ;

    }

    return 0 ;
    
}