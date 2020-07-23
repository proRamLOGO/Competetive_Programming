#include<iostream>
using namespace std ;

int **dp,n,m ;

void print() {

    for ( int i = 0 ; i <= n ; i++ )
        for ( int j = 0 ; j <= m ; ++j ) 
            cout << dp[i][j] << ((j==m)?'\n':' ') ;
    cout << endl ;
}

int solve( int *x, int n, int i, int s1, int s2 ) {

    if ( dp[i][abs(s1-s2)] != -1 )
        return dp[i][abs(s1-s2)] ;

    if ( n==i ) {
        dp[i][abs(s1-s2)] = abs(s1-s2) ;
        print() ;
        return dp[i][abs(s1-s2)];
    }
    print() ;
    dp[i][abs(s1-s2)] = min( solve(x,n,i+1,s1+x[i],s2), solve(x,n,i+1,s1,s2+x[i]) ) ;
    return dp[i][abs(s1-s2)] ;

}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin) ;
    freopen("output.txt","w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr) ;

    int sum=0 ;
    cin >> n;
    int *x = new int[n] ;
    for ( int *i = x ; i != x+n ; ++i ) cin >> *i, sum+= *i ;

    // // Top DOWN Solution
    m = sum;
    // dp = new int*[n+1] ;
    // for ( int i = 0 ; i <= n ; ++i ) {
    //     dp[i] = new int[sum+1] ;
    //     for ( int j = 0 ; j <= sum ; ++j  )
    //         dp[i][j] = -1 ;
    // }

    // // print() ;
    // cout << solve(x,n,0,0,0) << endl ;

    // // RESET
    // for ( int i = 0 ; i < n ; ++i  )
    //     delete dp[i] ;
    // delete dp ;


    // Bottom UP Solution
    
    dp = new int*[n+1] ;
    for ( int i = 0 ; i <= n ; ++i ) 
        dp[i] = new int[sum+1]{0} ;

    // print() ;

    for ( int i = 0 ; i <= n ; ++i )
        dp[i][0] = 1 ;
    
    for ( int i = 1 ; i <= n ; ++i ) 
        for ( int j = 1 ; j <= m ; ++j ) {
            dp[i][j] = dp[i-1][j] ;
            if ( x[i-1]<=j )
                dp[i][j] |= dp[i-1][j-x[i-1]] ;
        }

    // int ans = INT_MAX ;
    for ( int i = sum>>1 ; i > -1 ; --i )
        if ( dp[n][i] ) {
            cout << sum-2*i << endl ;
            break ;
        }


    

    


}