#include <bits/stdc++.h>
#define llui long long unsigned int 
#define sumn(n) n*(n+1)/2

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k ;
    string str ; 
    unordered_map< char, int > freq ;
    cin >> n >> k ;
    cin >> str ;
    for ( int i = 0 ; i < k ; ++i ) {
        char ch ;
        cin >> ch ;
        freq[ch] = 1 ;
    }
    // cout << str << ' ' << n << ' ' << k << endl ;
    int cnt = 0 ;
    vector< int > vals ;
    bool running = false ;
    
    for ( auto i : str ) {
        if ( freq[i] == 1 ) {
            if ( !running ) {
                vals.push_back( cnt ) ;
                running = true ;
                cnt = 1 ;
                continue ;
            }
            ++cnt ;
        } else 
            running = false ;
    }
    if ( running )
        vals.push_back(cnt) ;

    llui ans = 0 ;
    for ( auto i : vals ) {
        ans += sumn(i) ;
        // cout << i << endl ;
    }
    
    cout << ans << endl ;

}
