#include <iostream>

using namespace std;

int main() {
	
	int t ;
	cin >> t ;
	while ( t-- ) {
	    
        long int n, alices=0, bobs=0, sim=0 ;
        int a, b ;
        cin >> n >> a >> b ;
        
        long long int v ;
        
        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> v ;
            ( v%a == 0 && v%b == 0 )? sim++ : 1 ;
            ( v%a == 0 )? bobs++ : 1 ;
            ( v%b == 0 )? alices++ : 1 ;
        }
        
        bobs -= sim ;
        alices -= sim ;

        if ( sim == 0 ) {
            ( bobs > alices )? cout << "BOB\n" : cout << "ALICE\n" ;
        }
        else 
            ( bobs >= alices )? cout << "BOB\n" : cout << "ALICE\n" ;
	    
	}
	
	return 0;
}
