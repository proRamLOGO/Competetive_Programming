#include <bits/stdc++.h>
#include <unordered_map>
#define llui long long unsigned int
#define sui short unsigned int
#define M 1000000007

using namespace std ;

llui Bernoulli( int n, int k, vector< vector< llui > >& bernoulli ) {

    if ( n < k || n < 0 || k < 0 )
        return 0 ;
    if ( bernoulli[n][k] != 0 )
        return bernoulli[n][k] ;
    if ( k < n )
        return bernoulli[n][k] = ( Bernoulli(n-1,k,bernoulli)%M + Bernoulli(n-1,k-1,bernoulli)%M ) % M ;
    else if ( k == n ) 
        return bernoulli[n][k] = (2 * (Bernoulli(n-1,k-1,bernoulli)%M) ) % M ;
    
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k ;
    cin >> n >> k ;
    vector< int > arr(n) ;
    //vector< sui > freq(101,0) ;
    for ( auto i = 0 ; i < n ; ++i ) 
        cin >> arr[i] ;
    
    llui ans = 0;

    vector< llui > x(k+1,0) ;
    x[0] = 1 ;
    vector< vector< llui > > bernoulli(n+1,x) ;
    bernoulli[0][0] = 1 ;

    Bernoulli(n,k,bernoulli) ;

    cout << bernoulli[n][k]%M << endl ;

}