#include <bits/stdc++.h>
#define llui long long unsigned int 
#define M 1000000007

using namespace std ;

llui countDistinctXORs( int freq[2][2], int s, int l, string S ) {

    if ( s==l ) {
        cout << S << "   :    " << stoi(S,0,2) << endl ;
        return 1 ;
    }

    int left = 0, right = 0;

    // LEFT CALL TRY. MAKING CURR DIGIT 0
    if( (freq[0][0]>0 and freq[1][0]>0) or (freq[0][1]>0 and freq[1][1]>0) ) {
        if ( freq[0][0] + freq[1][0] > freq[0][1] + freq[1][1] and (freq[0][0]>0 and freq[1][0]>0) ) {
            --freq[0][0] ; --freq[1][0] ;
            left = countDistinctXORs( freq, s+1, l, S+'0' ) ;
            ++freq[0][0] ; ++freq[1][0] ;         //BACKTRACK
        } else if ( (freq[0][1]>0 and freq[1][1]>0) ) {
            --freq[0][1] ; --freq[1][1] ;
            left = countDistinctXORs( freq, s+1, l, S+'0' ) ;
            ++freq[0][1] ; ++freq[1][1] ;         //BACKTRACK
        }
    }

    // RIGHT CALL TRY. MAKING CURR DIGIT 1
    if( (freq[0][0]>0 and freq[1][1]>0) or (freq[0][1]>0 and freq[1][0]>0) ) {
        if ( freq[0][0] + freq[1][1] > freq[0][1] + freq[1][0] and (freq[0][0]>0 and freq[1][1]>0) ) {
            --freq[0][0] ; --freq[1][1] ;
            right = countDistinctXORs( freq, s+1, l, S+'1' ) ;
            ++freq[0][0] ; ++freq[1][1] ;         //BACKTRACK
        } else if ( (freq[0][1]>0 and freq[1][0]>0) ) {
            --freq[1][0] ; --freq[0][1] ;
            right = countDistinctXORs( freq, s+1, l, S+'1' ) ;
            ++freq[1][0] ; ++freq[0][1] ;         //BACKTRACK
        }
    }

    return ( (left%M + right%M ) % M ) ;
    

}

llui solve( string a, string b ) {

    int freq[2][2] = {0} ;
    // cout << freq[0][0] << ' ' << freq[0][1] << ' ' << freq[1][0] << ' ' << freq[1][1] << '\n' ;
    for ( int i = 0 ; i < a.size() ; ++i ) 
        ++freq[0][a[i]-'0'] ;
    for ( int i = 0 ; i < b.size() ; ++i ) 
        ++freq[1][b[i]-'0'] ;
    cout << freq[0][0] << ' ' << freq[0][1] << '\n' << freq[1][0] << ' ' << freq[1][1] << '\n' ;

    return countDistinctXORs( freq, 0, a.size(), "" ) ;

    // llui z = 1 ;
    // z

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output_DEBUG.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 
    int t ;
    cin >> t ;

    while( t-- ) {
        // cnt = 0 ;
        int n ;
        cin >> n ;
        string a, b ;
        cin >> a >> b ;
        cout << solve(a,b) << endl << endl ;

    }

    return 0 ;

}