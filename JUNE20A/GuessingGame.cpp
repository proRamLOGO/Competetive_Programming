// Author: proRam
// Name: Shubh Bansal
// Dated: June 6, 2020
// Question: https://www.codechef.com/JUNE20A/problems/GUESSG

#include <iostream>
using namespace std;
using ll = long long ;
int main() {
	
	ll n ; cin >> n ;
	
	ll lo1 = 1, lo2 = 1, hi1 = n, hi2 = n ;
	
	char response ;
	
	while (true) {
	    
	   ll mid1 = (lo1+hi1)>>1 ;
	   cout << mid1 << endl;
	   cin >> response ;
	   
	   if ( response == 'E' ) {
	       break ;
	   } else if ( response == 'G' ) {
	       lo1 = mid1+1 ;
	   } else {
	       hi1 = mid1-1 ;
	   } 
	    
	   ll mid2 = (lo2+hi2)>>1 ;
	   cout << mid2 << endl;
	   cin >> response ;
	   
	   if ( response == 'E' ) {
	       break ;
	   } else if ( response == 'G' ) {
	       lo2 = mid2+1 ;
	   } else {
	       hi2 = mid2-1 ;
	   }
	   
	   if ( lo1>hi1 and lo2>hi2 )
	    break ;
	   
	}
	
	return 0;
}
