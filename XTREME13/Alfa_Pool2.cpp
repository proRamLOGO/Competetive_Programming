#include <bits/stdc++.h>
#define llui long long unsigned int 
#define M 1000000007
using namespace std ;

llui ans ; 

void solve( llui n, vector< llui >& v, llui score ) {

    if ( score > n or v.size() > 2*n )
        return ;
    
    if ( score == n ) {
        if (0) {
            for ( auto i : v )
                cout << i << ' ' ;
            cout << endl ;
        }
        ans = (ans+1)%M ;
        return ;
    }

    llui num = 1 ;
    while ( num+score <= n ) {

        v.push_back(num) ;
        solve( n, v, score+num ) ;
        v.pop_back() ;
        num <<= 1 ;
        num |= 1 ;

    }

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llui t ;
    cin >> t ;

    while ( t-- ) {
        ans = 0 ;
        llui n ;
        cin >> n ;
        vector< llui > v ;
        solve( n , v, 0 ) ;

        cout << (ans*2)%M << endl ;

    }

}