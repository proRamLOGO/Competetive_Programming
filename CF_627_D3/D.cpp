#include <bits/stdc++.h>
#define llui long long unsigned int 
#define li long int 

using namespace std ;
 
int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    li n ;
    cin >> n ;
    vector< llui > a(n), b(n) ;

    for ( li i = 0 ; i < n ; ++i ) cin >> a[i] ;
    for ( li i = 0 ; i < n ; ++i ) cin >> b[i] ;

    for ( li i = 0 ; i < n ; ++i ) cout  << a[i]  << ' ';
    cout << endl ;
    for ( li i = 0 ; i < n ; ++i ) cout  << b[i]  << ' ' ;
cout << endl ;cout << endl ;
    li ans = 0 ;

    for ( li i = 0 ; i < n ; ++i ) {
        for ( li j = i+1 ; j < n ; ++j ) {

            cout << a[i] << " " << a[j] << "       " << b[i] << " " << b[j] << endl ;
            cout << a[i]+a[j] << "  " << b[i]+b[j] << endl << endl ;

            if ( a[i]+a[j] > b[i]+b[j] )
                ++ans ;
        }
    }

    cout << ans << endl ;

}
