#include <bits/stdc++.h>
#define llui long long unsigned int 
#define M 1000000007
using namespace std ;

llui dp[100001][17][2] ; 

llui solve( llui target, llui win, llui lose, llui score ) {

    if ( target > score or lose == 2 )
        return 0 ;
    if ( target == score )
        return 1 ;

    if ( dp[target][win][lose] != -1 )
        return dp[target][win][lose] ;
    
    llui var = 0 ;
    var += solve( target, 0, lose+1, score ) % M ;
    llui z ;
    z = 1<<win ;
    var += solve( target + z, win + 1, 0, score ) % M ;
    return dp[target][win][lose] = var ;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llui t ;
    cin >> t ;

    while ( t-- ) {
        llui score ;
        cin >> score ;

        memset(dp,-1,sizeof(dp)) ;
        solve( 0, 0, 0, score ) ;

        cout << dp[0][0][0]%M << endl ;

    }

}