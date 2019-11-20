#include <iostream>
#include <vector>

using namespace std ;

long long int minStepsToOne( long long int n ) {

    if ( n==1 ) return 0 ;

    long long int ans1=long long int_MAX , ans2=long long int_MAX , ans3=long long int_MAX ;
    if ( n>1)
        ans1 = minStepsToOne( n-1 ) ;
    if ( n%2==0 )
        ans2 = minStepsToOne( n/2 ) ;
    if ( n%3==0)
        ans3 = minStepsToOne( n/3 ) ;
    
    return 1 + min(ans1,min(ans2,ans3)) ;

}

long long int main() {

    long long int n ;
    cin >> n ;
    long long int ans = minStepsToOne( n ) ;
    cout << ans << endl ;

}