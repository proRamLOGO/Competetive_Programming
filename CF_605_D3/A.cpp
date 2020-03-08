#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q ;
    cin >> q ;

    while ( q-- ) {

        llui a, b, c ;
        cin >> a >> b >> c ;

        // Sorting a,b,c ;
        llui A = min( a, min( b, c ) ) ;
        llui B = max( a, max( b, c ) ) ;
        llui C = a+b+c -A-B ;

        a = A ;
        b = C ;
        c = B ;

        // cout << a << " " << b << " " << c << endl ;

        if ( ( a==b and ( b==c or b==c-1) ) or ( c==b and ( a==b or b==a+1) )  )
            cout << 0 << endl ;
        
        else if ( a==b and c > b+1 ) 
            cout << ( 2 * llabs(c-1-b-1) ) << endl ;
        
        else if ( a < b-1 and c==b ) 
            cout << ( 2 * llabs(c-1-a-1) ) << endl ;

        else 
            cout << ( llabs(b-a-1) + llabs(c-1-b) + llabs( c-a-2 ) ) << endl ;

    }

}
