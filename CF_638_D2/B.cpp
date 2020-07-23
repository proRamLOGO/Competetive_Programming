// Author: proRam
// Name: Shubh Bansal
// Dated: 
// Question: https://codeforces.com/contest/1348/problem/0

#include <bits/stdc++.h>
#define DBG(x) cout << "| " << #x << " : " << x << ' '
#define DBG1(n,j) cout << "| " << #n << "[" << j << "] = " << n[j] << ' '
#define ENDL cout << endl

using namespace std;
 
using ll = int ;
using ull = unsigned long long ;
using pll = pair<ll, ll> ;
using vi = vector<int> ;
using vll = vector<ll> ;
using vpll = vector<pll> ;
using vvll = vector<vll> ;
using vs = vector<string> ;

struct TC {

    vll freq ;
    int size ;
    TC( int k ) {
        freq.resize(k+1) ;
    }

};

int32_t main(int argc, char** argv) noexcept {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    // TIME("main") {

    int t=1 ;
    cin >> t ;
    
    while( t-- ) {
        
        int n, k ;
        cin >> n >> k ;
        
        vi v(n) ;
        set<int> s ;
        for( int i = 0 ; i < n ; ++i) {
            cin >> v[i] ;
            s.insert(v[i]) ;
        }

        if ( s.size() > k ) {
            cout << -1 << endl ;
            continue ;
        }

        vi ans ;
        for ( auto i : s )
            ans.emplace_back(i) ;
        int e = ans[ans.size()-1] ;
        while( ans.size()!=k )
            ans.emplace_back(e) ;

        cout << ans.size()*n << endl ;
        for( int i = 0 ; i < n ; ++i ) 
            for ( auto j : ans )
                cout << j << ' ' ;
        
        ENDL;
        

    }

    return 0 ;   

}
