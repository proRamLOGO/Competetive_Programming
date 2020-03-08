#include <bits/stdc++.h>
#include <tuple>
#define llui long long unsigned int 
#define lli long long  int 
#define lui long unsigned int 
#define M 1000000007
#define MAX 10000
using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while( t-- ) {
        
        int n ;
        cin >> n ;
        vector< pair< llui, llui > > v(n) ;

        for ( int i = 0 ; i < n ; ++i ) {
            llui x, y ;
            cin >> x >> y ;
            v[i] = make_pair(x,y) ;
        }

        sort( v.begin(), v.end() ) ;

        int ans = -1 ;

        for ( int i = 0 ; i < n ; ++i )  {

            llui r1 = v[i].second ;

            for ( int j = 0 ; j < n ; ++j ) {

                llui l2 = v[j].first ;
                int rng_cnt = -1 ;

                if ( l2 > r1 ) {

                    rng_cnt = 0 ;
                    for ( int k = 0 ; k < j ; ++k ) 
                        if ( v[k].second > l2 )
                            ++rng_cnt ;

                    if ( ans == -1 ) 
                        ans = rng_cnt ;
                    else 
                        ans = min( ans, rng_cnt ) ;
                }

            }

        }
            
        cout << ans << endl ;


    }

    return 0 ;

}