#include <bits/stdc++.h>
#define llui long long unsigned int 
#define lui long unsigned int 
#define M 1000000007
#define MAX 10000
using namespace std ;

lui inv_fact[MAX + 1]; 
lui inv[MAX + 1]; 
lui fact[MAX + 1]; 
  
void prepare_inv() { 
    inv[0] = inv[1] = 1; 
    for (int i = 2; i <= MAX; i++) 
        inv[i] = inv[M % i] * (M - M / i) % M; 
} 

void prepare_inv_fact() { 
    inv_fact[0] = inv_fact[1] = 1; 
    for (int i = 2; i <= MAX; i++) 
        inv_fact[i] = (inv[i] * inv_fact[i - 1]) % M; 
} 
  
void prepare_fact() { 
    fact[0] = 1; 
    for (int i = 1; i <= MAX; i++) { 
        fact[i] = (fact[i - 1] * i) % M ; 
    } 
} 
  
lui nCr( int n, int r) { 
    return ((fact[n] * inv_fact[r]) % M * inv_fact[n - r]) % M; 
} 

llui summation( vector<int> ones, int n ) {

    llui ans = 0 ;

    for( int i = 0 ; i < ones.size() ; ++i ) {
        // cout << ones[i] << ", " ;
        ans = ( ans + nCr(n,ones[i])%M ) % M ;
    }
    // cout << endl ;
    return ans%M ;

}

llui solve( string a, string b, int n ) {

    int arr[2][2] = {0} ;    
    for ( int i = 0 ; i < a.size() ; ++i ) 
        ++arr[0][a[i]-'0'] ;
    for ( int i = 0 ; i < b.size() ; ++i ) 
        ++arr[1][b[i]-'0'] ;
    
    vector< int > ones ;
    ones.push_back( max( arr[0][1], arr[1][1] ) - min( arr[0][1], arr[1][1] ) ) ;
    int rem_zeroes = min(arr[0][0], arr[1][0]);
    rem_zeroes = min( rem_zeroes, min( arr[0][1], arr[1][1] ) ) ;
    for( int i = 0 ; i < rem_zeroes ; ++i ) {
        ones.push_back( ones[ones.size()-1]+2 ) ;
    }

    return summation( ones, n )%M ;

}


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output_DEBUG.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prepare_inv(); 
    prepare_inv_fact(); 
    prepare_fact(); 

    int t ;
    cin >> t ;

    while( t-- ) {
        
        int n ;
        cin >> n ;
        string a, b ;
        cin >> a >> b ;
        cout << solve(a,b,n) << endl ;

    }

    return 0 ;

}