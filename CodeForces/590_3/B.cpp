#include <bits/stdc++.h>

#define lui long unsigned int 
#define llui long long unsigned int 

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k ;
    vector< lui > v(n) ;
    //unordered_map< lui, int > freq ;
    unordered_map< lui, bool > inhere ;

    for ( auto i = 0 ; i < n ; ++i ) {
        cin >> v[i] ;
        inhere[v[i]] = false ;
    }
    //int d = freq.size() ;

    queue< lui > screen;

    for ( auto i : v ) {

        if ( inhere[i] != true ) {
            inhere[i] = true ;
            screen.push(i) ;
            if ( screen.size() > k ) {
                inhere[screen.front()]=false ;
                screen.pop() ;
            }
        }

    }

    // Output
    int i = 0 ;
    vector< lui > ans(screen.size()) ;
    cout << screen.size() << endl ;
    while ( !screen.empty() ) {
        ans[i++] = screen.front() ;
        screen.pop() ;
    }

    for ( auto j = i-1 ; j > -1 ; --j )
        cout << ans[j] << ' ' ;

    cout << endl ;

}