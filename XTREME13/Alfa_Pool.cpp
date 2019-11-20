#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

int ans ; 

void solve( int target, vector< int >& v, int score ) {
    
    if ( score == target ) {
        cout << score << ' ' << target << endl  ;
        for ( auto i : v )
            cout << i << ' ' ;
        cout << "here" << endl ;
        
        ++ans ;
        return ;
    }
    if( v.size() > 3*target or score > target || ( v.size() >= 2 && v[v.size()-1]==-1 && v[v.size()-2]==-1  ) )
        return ;

  

    if ( v.size() == 0 || v[v.size()-1] == -1 ) {
        v.push_back(1) ;
        solve( target, v, score+1 ) ;
        return ;
    }
    
    for ( auto i : v )
        cout << i << ' ' ;
    cout << endl ;
    
    v.push_back(v[v.size()-1]*2) ;
    solve( target, v, score+(v[v.size()-1]*2) ) ;
    v[v.size()-1] = -1 ;
    solve( target, v, score ) ;
    v.pop_back() ;

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

        int n ;
        cin >> n ;
        vector< int > v ;
        ans = 0; 
        solve(n, v, 0) ;

    }

    cout << ans << endl ;

}