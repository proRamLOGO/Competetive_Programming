// Author: proRam
// Name: Shubh Bansal
// Dated: 
// Question: https://codeforces.com/contest/1342/problem/D

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
    // cin >> t ;
    
    while( t-- ) {
        
        ll n, k ;
        cin >> n >> k ; 
        vll v(n), c(k+1), freq(k+1) ;
        for ( ll i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            freq[v[i]]++ ;
        }
        for ( ll i = 0 ; i < k ; ++i ) {
            cin >> c[i+1] ;
        }

        vector<TC> ans ;

        while ( true ) {
            ll used = 0 ;
            TC test(k+1) ;
            for ( ll j = k ; j>0 ; --j ) {
                ll limit = c[j]-used ;
                
                if ( limit < 1 and freq[j]==0 ) continue ;
                else if ( limit < 1 ) break ;

                ll &a = freq[j] ;
                if ( (a/limit) > 0ll ) {
                    used += limit ;
                    a-=limit;
                    test.freq[j] += limit ; 
                } else if ( a%limit != 0 ) {
                    used += (a%limit) ;
                    test.freq[j] += (a%limit) ;
                    a = 0 ;
                }
                // cout << "   " ;
                // DBG(j) ; DBG(limit) ; DBG1(freq,j) ; DBG(a) ; DBG(used) ;
                // ENDL ;
            }
            if ( used == 0 )
                break ;
            test.size = used ;
            ans.push_back(test) ;
            // ENDL ;
        }

        ll nact = ans.size() ;

        // all testcs made ;

        cout << nact << endl ;

        for ( auto i : ans ) {
            cout << i.size << ' ' ;
            for ( int j = 1 ; j <= k ; ++j ) {
                if ( i.freq[j] == 0 ) continue ;
                else 
                    for ( int l = 0 ; l < i.freq[j] ; ++l ) 
                        cout << j << ' ' ;
            }
            ENDL ;
        }

        // cout << "\n\n================================================================\n" << endl ;

    }

    return 0 ;   

}
