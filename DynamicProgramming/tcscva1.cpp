#include<iostream>
#include<vector>

using namespace std ;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin) ;
    freopen("output.txt","w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr) ;

    int lh,rh,lw,rw ;
    cin >> lh >> rh >> lw >> rw ;

    int MAX = rh*rw+1 ;
    vector< vector< int > > dp(rh+1,vector<int>(rw+1)) ;
    
    for ( int i = 1 ; i <= rh ; ++i ) {
        for ( int j = 1 ; j <= rw ; ++j ) {

            int h=i,w=j ;
            if ( i>=j ) {
                h -= j ;
            } 
            if ( i<=j ) {
                w -= i ;
            }
            dp[i][j] = 1 + dp[h][w] ;
        }
    }

    long int ans = 0 ;

    for ( int i = lh ; i <= rh ; ++i )
        for ( int j = lw ; j<= rw ; ++j )
            ans += dp[i][j] ;

    cout << ans << endl ;

}