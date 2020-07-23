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
        string s ;
        cin >> n >> k >> s ;
        // vector<char> v(n) ;
        // for( int i = 0 ; i < n ; ++i) {
        //     cin >> v[i] ;
        // }
        sort(s.begin(),s.end()) ;
        // vector<vector<char> > ans(k,vector<char>(0)) ;

        // for ( int i = 0 ; i < n ; ++i ) {
        //     ans[i%k].emplace_back(s[i]) ;
        // }

        // for( auto i : ans[k-1] )
        //     cout << i ;
        
        string ans = "" ;

        int i=0;
        for ( i = 0 ; i <= n-k ; i+=k ) {
            ans += s[i] ;
        }
        ans += s.substr(n-k+1) ;

        cout << ans << endl ;
       
    }

    return 0 ;   

}
