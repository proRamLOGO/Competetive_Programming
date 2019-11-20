#include <iostream>

using namespace std ;

int cceil( int x ) {

    int r1 = x*0.75 ;
    float r2 = x*0.75 ;

    return ( r2-r1 > 0 )? r1+1 : r1 ;

}

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        int l ;
        string s ;
        cin >> l >> s ;

        int pres = 0, req, expec, bal=0 ;
        for ( auto i = 0 ; i < l ; ++i ) {
        
            if ( s[i] == 'P' ) 
                ++pres ;
            
            if ( s[i]=='A' ) {
                if ( s[i-2]=='P' || s[i-1]=='P' || s[i+2]=='P' || s[i+1]=='P' )
                    ++bal ;
                    cout << i << endl ;
            }

        }

        expec = cceil(l) ;
        req = expec - pres ;

        if ( bal >= req ) 
            cout << req << endl ;
        else 
            cout << -1 << endl ;
        

    }

}