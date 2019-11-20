#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t ;
    while ( t-- ) {
        //cout << "\n----------------------------\n" ;
        long long int n,k ;
        long long int ans = 1;

        cin >> n >> k ;
        //cout << endl ;
        
        if ( k==1 ) {
            cout << ( n * (n-1) ) % 1000000007 << endl;
            continue ;
        }
                
        long long int a = (( ((2*n)/k) - k + 1 )  /  2) ;
        
        if ( a <= 0 || n < k ) {
            
            cout << -1 << endl ;
            continue ;
            
        }
        
        long long int s =  ( ( k * ( (2*a) + k - 1 ) ) / 2 ) ;
        
        //cout << "\nsum = " << s << endl ;

        for ( auto i = 0 ; i < k ; ++i ) {

            
            if ( i == ( k - n + s ) ) a++ ;
            //cout << a << " " ;
            ans = ( ( ans % 1000000007 ) * ( ( (a*a) - a ) % 1000000007 ) ) % 1000000007;
            //ans = ans % 1000000007 ;
            a++ ;

        }  

        
        cout<< ans % 1000000007 << endl ;
/*
6
33 6
33 5
36 6
36 5
30 6
30 5
*/
       

    }    

}