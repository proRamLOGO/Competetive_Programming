#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std ;

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        int n; 
        bool f= 0 ;
        cin >> n ;

        vector< int > v(n), xor1(n+1), sum(n,0) ;


        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            if ( f ) {
                sum[i] = sum[i-1] + v[i] ;
            }
            else f=1 ;
        }

        xor1[0] = 0 ;
        for ( auto i = 0 ; i < n ; ++i ) {
            xor1[i+1] = xor1[i]^v[i] ;
        }

        int ans = 0 ;

        unordered_map< int, vector< int > > h ;

        for ( auto i = 0 ; i < n+1 ; ++i ) 
            h[xor1[i]].push_back( i ) ;
        

        //for ( auto i : xor1 ) 
            //cout << i << ' ' ;

        for ( auto i : h ) {
            f = 0 ;
            int prev=0, next ; 
            for ( auto j : i.second ) {
                if ( f!=0 ) {
                    next = j ;
                    ans += next-prev-1 ;
                    prev = next ;
                    //if ( i.first == 0 ) 
                        //ans += next + prev ;     
                }
                else {
                    prev = j ;
                    f = 1;    
                }
            } 
        }
        cout << ans << '\n' ;

    }

}


        /*
        unordered_map< int, vector< int > > h ;

        for ( auto i = 0 ; i < n ; ++i ) 
            h[xor1[i]].push_back( i ) ;
        

        for ( auto i : xor1 ) {
            cout << i << ' ' ;
        }
        cout << "\n\n\n";

        cout << '\n' << '\n' ;
        for ( auto i : h ) {
            f = 0 ;
            int prev, next ; 
            for ( auto j : i.second ) {
                if ( f==0 ) {
                    f=1 ;
                    continue ;
                    prev = j ;
                }
                next = j ;
                ans += next-prev ;
                if ( i.first == 0 ) {
                    ans += next + prev ;
                }
                prev = next ;      
            } 
        }
        */