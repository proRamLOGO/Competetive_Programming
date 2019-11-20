#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

llui curr, b ;
string ans ;

llui fpow( llui n, llui x ) {

    if ( x==0 )
        return 1 ;

    llui res = fpow(n, x/2 ) ;
    if ( x%2 ) 
        return n * res * res ;
    else 
        return res * res ;

}

void solve( llui l ) {
    
    if ( l == 0 )
        return ;

    llui skip = 0 ;

    llui i ;

    for ( i = 0 ; i < b ; ++i ) {
        //llui p1 = pow(b,l - 1) ;
        llui p2 = fpow(b,l - 1) ;
        //cout << endl << b << '^' << l-1 << " : " << p1 << ' ' << p2 << endl ;
        if ( skip + p2 < curr )
            skip += p2 ;
        else 
            break; 
    }

    curr -= skip ;

    char ch = 'a' + i ;
    ans += ch ;

    solve(l-1) ;
    
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

        llui X ;
        cin >> b >> X ;
        
        llui i, v = 0 ;

        for ( i = 1 ; ; ++i ) {
            llui pw = pow(b,i) ;
            if ( v >= (X+1-i*pw) )
                break ;
            v += i * pw ;
        }
        llui p = (X-v) / i ;

        llui l = i ;
        curr = p+1 ;

        ans = "" ;
        solve(l) ;

        cout << ans[X-v-p*l] << endl ;

    }



}
