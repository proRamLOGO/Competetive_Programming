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
        
        int n ;
        cin >> n ;

        if (n==2) {cout << 2 << endl; continue ;}
        if (n==4) {cout << 6 << endl; continue ;}

        int k = n/2 ;
        ull s1 = 0, s2 = 0, z=1;

        s1 = z<<n ;
        for ( int i = 1 ; i < k ; ++i ) {
            // DBG(i) ;
            // DBG((z<<i)) ;
            s1 += (z<<i) ;
            // ENDL;
        }
        // ENDL;
        for ( int i = k ; i < n ; ++i ) {
            // DBG(i) ;
            // DBG((z<<i)) ;
            s2 += (z<<i) ;
            // ENDL;
        }
        
        // DBG(s1), DBG(s2), ENDL ;

        if ( s1 > s2 ) 
            cout << (s1-s2) << endl ;
        else
            cout << (s2-s1) << endl ;

    }

    return 0 ;   

}
