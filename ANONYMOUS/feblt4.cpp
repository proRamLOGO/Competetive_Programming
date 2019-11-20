#include <iostream>
#include <math.h>

using namespace std;

int main() {
	
	int t ;
	cin >> t ;
	
	while ( t-- ) {
	    
	    long long int a, d1=1, d2=1, fprev, f, p=1 ;
	    bool fd1 = 0, fd2 = 0 ;
	    
	    cin >> a ;
	    
	    for ( auto i = 1 ; i <= a ; ++i ) {
	        
	        f = a*i - pow(2,i) + 1 ;

	        if ( i==1 )
	            fprev = f ;
	        
            if ( f > fprev ) 
                p = i ;
            

	        //cout << "\nf = " << f << "    and fprev = " << fprev  ;
	        
	        if ( f < fprev && !fd1 ) {
                d1 = p ;
                fd1 = 1 ;
	        }
	        
 	        if ( f < 0 && !fd2 ) {
 	            d2 = i-1 ; 
 	            fd2 = 1 ;
 	        }
 	        
 	        fprev = f ;
 	        
 	        if ( fd1 && fd2 ) 
 	            break ;
 	        
 	        
	    }
	    
	    cout << d2 << ' ' << d1 << endl ;
	    
	    
	}
	
	return 0;
}
