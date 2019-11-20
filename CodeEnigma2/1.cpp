#include <bits/stdc++.h>
#define llui long long unsigned int
#define M 1000000007

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen("output.txt", "w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while ( t-- ) {
        int n ;
        cin >> n  ;
        vector< int > arr(n), cf(n,0) ;
        map< int, int > freq;

        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> arr[i];
            ++freq[arr[i]];
        }

        int distinct = 0 ;
        int cnt = 0, prev=0 ;
        bool pf = false ;
        for ( auto i = freq.begin() ; i != freq.end() ; ++i ) {
            if ( !pf ) {
                pf = 1 ;
            }
            prev += i->second ;
            i->second = prev ;
        }
        
        for ( auto i : arr ) 
            cout << n-freq[i] << ' ';
        // << i << ' ' << freq[i] << '\n' ;
        
        cout << '\n' ;;

    }
    cout << endl ;
    
}