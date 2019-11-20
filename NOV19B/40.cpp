#include <iostream>
#include <bits/stdc++.h>
#define llui long long unsigned int
#define ui unsigned int
using namespace std ;

int min( long long int a, long long int b ) {
    if ( a < b ) 
        return a ;
    return b ;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt","w",stdout) ;    
    #endif

    int t ;
    cin >> t ;

    while ( t-- ) {
 
        ui n, k ;
        cin >> n >> k ;

        vector< llui > v(n) ;

        for ( auto i = 0 ; i < n ; ++i )
            cin >> v[i] ;

        deque< ui > mx, mi ;

        ui i = 0 ; 
        for( ; i < k ; ++i ) {

            // Max
            while ( !mx.empty() and v[mx.back()] <= v[i] )
                mx.pop_back() ;
            
            mx.push_back(i) ;

            // Min
            while ( !mi.empty() and v[mi.back()] >= v[i] )
                mi.pop_back() ;
            
            mi.push_back(i) ;

        }

        //cout << "Max        Min \n" ;
        int ans = v[mx.front()] - v[mi.front()] ;
        //cout << mx.front() << "         " << mi.front() <<endl ;
        
        for ( ; i < n ; ++i ) {
            
            // Max
            while ( !mx.empty() and mx.front()+k <= i )
                mx.pop_front() ;

            while ( !mx.empty() and v[mx.back()] <= v[i] )
                mx.pop_back() ;
            
            mx.push_back(i) ;
            
            //Min

            while ( !mi.empty() and mi.front()+k <= i )
                mi.pop_front() ;

            while ( !mi.empty() and v[mi.back()] >= v[i] )
                mi.pop_back() ;
            
            mi.push_back(i) ;


            //cout << mx.front() << "         " << mi.front() <<endl ;
            
            ans = min( ans,  (v[mx.front()] - v[mi.front()]) ) ;

        }

        cout << ans << endl ; 
    }
}