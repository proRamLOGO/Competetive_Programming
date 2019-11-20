#include <iostream> 
#include <vector>
#include <algorithm>
  
using namespace std; 

bool cmp( vector< int >& x, vector<int>& y ) {

    return x[1] > y[1] ;

}

int minSwaps(vector< int >& arr, int n) { 
  
    vector< int > b(n), c(n) ;
    int B=0, C=0 ;

    for ( auto i = 0 ; i < n ; ++i ) {
        
        if ( arr[i] == 1 ) B++ ;
        b[i] = B ;
    
        if ( arr[n-i-1] == 1 ) C++ ;
        c[n-i-1] = C ;

    }

    int res = 0 ;

    
    for ( auto i = 0 ; i < n ; ++i ) {
        

        if ( arr[i] == 0 ) {
            res += min(b[i], c[i]) ;
        }

    }

    return res ;

    /*int ones = 0; 
  
    for (int i = 0; i < n; i++) { 
        if ( arr[i] == 1 ) 
            ++ones; 
    } 
    int x = ones; 
    
    int maxOnes = INT8_MIN; 
    
    vector< int > preCompute(n) ;
    
    if ( arr[0] == 1 ) 
            preCompute[0] = 1; 
    
    for (auto i = 1; i < n; i++) { 
    
        if (arr[i] == 1) 
            preCompute[i] = preCompute[i - 1] + 1; 
        else
            preCompute[i] = preCompute[i - 1]; 
    
    }
    
    for (auto i = x - 1; i < n; i++) { 
        
        if ( i == (x - 1) )  
            ones = preCompute[i]; 
        else 
            ones = preCompute[i] - preCompute[i - x]; 
        
        if ( maxOnes < ones ) 
            maxOnes = ones; 

    }
    
    return x - maxOnes; */
} 
  
// Driver Code 
int main() { 

    int t ;

    cin >> t ;

    while ( t-- ) {

        int n , k ;

        cin >> n >> k ;

        vector< int > v(n), x(n), subf(2) ;
        vector< vector< int > > grid(n, x), freq(n+1, subf) ;

        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            grid[v[i]][i] = 1 ;
            ++freq[ v[i] ][1] ;
            freq[v[i]][0] = v[i] ;
        }

        sort( freq.begin(), freq.end(), cmp ) ;

        if ( freq[0][1] < k ) {
            cout << -1 << endl ;
            continue ;
        }


        int ans = INT8_MAX ;

        for ( auto i = 0 ; i < n && freq[i][1] >= k ; ++i ) {
            
            vector< int > req = grid[freq[i][0]] ;
            int max = minSwaps( req, n ) ;

            //cout << "\nSwaps required to group all " << freq[i][0] << "s together is  : " << max ;  

            if ( max < ans ) 
                ans = max ;

        }

        cout << ans << endl ;

    }

} 