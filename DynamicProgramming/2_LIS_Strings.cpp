#include<iostream>
using namespace std ;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin) ;
    freopen("output.txt","w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr) ;

    int n;
    string x ;
    cin >> n >> x ;

    int *dp = new int[n]{0} ;
    for ( int i = 0 ; i < n ; ++i ) {
        for ( int j = i-1 ; j > -1 ; --j ) 
            if ( x[j] <= x[i] ) 
                dp[i] = max(dp[i],dp[j]) ;
        ++dp[i] ;
    }

    for ( int i = 1 ; i < n ; ++i )
        dp[i] = max(dp[i],dp[i-1]) ;

    cout << dp[n-1] << '\n' ;

}