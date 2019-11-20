#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

int solve( vector< int >  ) 

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int t ;
    cin >> t ;

    while ( t-- ) {

        int n ;
        cin >> n ;

        vector< int > arr(n), cumORl(n), cumORr(n) ;
        for ( auto i = 0 ; i < n ; ++i ) 
            cin >> arr[i] ;
        
        cumORl[0] = arr[0] ;
        cumORr[n-1] = arr[n-1] ;

        for ( auto i = 1 ; i < n ; ++i ) 
            cumORl[i] = arr[i] | cumORl[i-1] ;
        for ( auto i = n-2 ; i > -1 ; --i ) 
            cumORl[i] = arr[i] | cumORr[i+1] ;


        

    }

    return 0 ;

}