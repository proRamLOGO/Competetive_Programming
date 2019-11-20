#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std; 

int subsetXOR(vector<int>& arr, int n, int k) {

    int max_ele = arr[0]; 
    for (int i=1; i<n; i++) 
       if (arr[i] > max_ele) 
           max_ele = arr[i]; 
  
    int m = (1 << (int)(log2(max_ele) + 1) ) - 1; 
  
    int dp[n+1][m+1]; 
  
    for (int i=0; i<=n; i++) 
        for (int j=0; j<=m; j++) 
            dp[i][j] = 0; 
  
    dp[0][0] = 1; 
  
    for (int i=1; i<=n; i++) 
        for (int j=0; j<=m; j++) 
            dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]]; 
  
    return dp[n][k]; 
} 
  
int main() { 
    
    int n, k = 0 ;
    cin >> n ;

    vector< int > v(n) ;

    for ( auto i = 0 ; i < n ; ++i )    
        cin >> v[i] ;

    cout << subsetXOR(v, n, k)-1; 
    return 0; 
} 