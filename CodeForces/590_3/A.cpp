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

        int n ;
        cin >> n ;
        llui sum=0, x ;
        for ( auto i = 0 ; i < n ; ++i ){
            cin >> x ;
            sum += x ;
        }
        llui avg = sum/n ;

        if ( n*avg < sum ) 
            ++avg ;
        
        cout << avg << endl ;

    }


}