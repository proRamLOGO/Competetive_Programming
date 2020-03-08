#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

int cntdigits( llui n ) {
    int cnt ;
    for ( cnt = 0 ; n != 0 ; ++cnt, n/=10 ) ;
    return cnt ;
}

bool all9( llui n ) {

    while ( n != 0 ) {
        if ( n%10 != 9 )
            return false ;
    }
    return true ;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while ( t-- ) {

        llui a, b, x ;
        cin >> a >> b ;

        int digits = ceil(log10(b)) ;
        // cout << "dig : " << digits <<endl;
        if ( b+1 != pow(10,digits) )
            --digits ;
        double res = a * digits ;
    uint64_t
        cout << res << endl ;
    }

}

