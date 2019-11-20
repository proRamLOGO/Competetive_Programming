#include <bits/stdc++.h>
#include <unordered_map>
#define llui long long unsigned int
#define sui short unsigned int
//#define nCr(n,r) fact[n]/fact[n-r]*fact[r]

using namespace std ;

llui nCr(int n,int k)
{
    if( k > n-k )
        k=n-k;
    
    llui ans = 1;
    for(int i=0;i<k;i++) {
        ans *= (n-i);
        ans /= (i+1);
    }
    
    return ans ;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector< llui > fact(51) ;
    fact[0] = 1 ;
    fact[1] = 1 ;
    fact[2] = 2 ;
    for ( int i = 3 ; i < 51 ; ++i )
        fact[i] = fact[i-1]*i ;

    int t ;
    cin >> t ;
    while( t-- ) {

        int n, k ;
        cin >> n >> k ;
        vector< int > arr(n) ;
        //vector< sui > freq(101,0) ;
        for ( auto i = 0 ; i < n ; ++i ) { 
            cin >> arr[i] ;
            //++freq[arr[i]] ;
        }
        
        sort(arr.begin(),arr.end()) ;
        unordered_map< int, int > freq ;
        int g = 0, r = 0 ;
        bool f = true ;

        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = i ; j <= n ; ++j ) {
                if ( j < n && arr[i]==arr[j] ) 
                    ++freq[arr[i]] ;
                else {
                    if ( g + freq[arr[i]] > k ) {
                        r = k - g ;
                        cout << nCr(freq[arr[i]],r) << endl ;
                        f = 0 ;
                        break ;
                    }
                    else if ( g + freq[arr[i]] == k ) {
                        cout << 1 << endl ;
                        f = 0 ;
                        break ;
                    }
                    else {
                        g += freq[arr[i]] ;
                        i = j - 1 ;
                        break ;
                    } 
                }
            }
            if ( !f )
                break ;
        }
    }
}