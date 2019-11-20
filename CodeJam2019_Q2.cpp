#include <iostream>
#include <string>

using namespace std ;

int main() {
    
    int T ;
    cin >> T ;
    
    for ( auto t = 0 ; t < T ; ++t ) {
        
        int n ;
        cin >> n ;
        string s,x="" ;
        cin >> s ;

        for ( auto i = 0 ; i < 2*(n-1) ; ++i )             
           ( s[i] == 'E' )? x += 'S' : x += 'E' ; 

        cout << "Case #" << t+1 << ": " << x << endl ;
        
    }   
}