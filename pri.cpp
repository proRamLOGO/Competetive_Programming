#include<bits/stdc++.h>

using namespace std;

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen( "output.txt", "w", stdout ) ;
    #endif

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int t, mt = -1;
    cin >> t;
    int quer[t], ans[t] ;
    for ( int T = 0 ; T < t ; ++T ) {
        cin >> quer[T] ;
        mt = max(mt,quer[T]) ;
    }
    // cout << mt << endl ;
    
    vector<bool> prime(mt+1,1) ;
    vector<int > dp(mt+1,0) ; 
  
    for ( auto i = 2; i*i <= mt; ++i ) 
        if (prime[i]) {
            dp[i] = dp[i-1]+1 ;
            for ( auto j = i*i ; j <= mt ; j += i ) 
                prime[j] = 0 ;
        }
        else
            dp[i] = dp[i-1] ;
    
    for ( auto i = 2; i <= mt; ++i ) {
        dp[i] = dp[i-1] ;
        if (prime[i]) 
            ++dp[i] ;
    }
    
    // cout << endl ;
    for ( int T = 0 ; T < t ; ++T ) {
        int n   = quer[T] ;
        int res = dp[n] ;
        // cout << res << endl ;
        if(!res)
            cout << "Harshit" << endl;
        else if(res%2)
            cout << "Aahad" << endl;
        else
            cout << "Harshit" << endl;

    }       
	return 0;
}
    