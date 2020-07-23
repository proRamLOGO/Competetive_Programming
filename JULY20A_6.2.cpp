#include <bits/stdc++.h>
using namespace std;

using ll = long long ;
using ull = unsigned long long ;
using pll = pair<ll, ll> ;
using vll = vector<ll> ;
using vpll = vector<pll> ;
using vvll = vector<vll> ;
using vs = vector<string> ;

pll days( ll patients, ll med ) {
    
    ll pop = patients ;
    int cnt = 1;
    while ( med < patients ) {
        patients = min( pop, (patients-med)*2 ) ;
        med *= 2 ;
        ++cnt ;   
    }
    return (pll){patients<<1ll,cnt} ;
    
}

int32_t main(int argc, char** argv) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    int t;
    cin >> t ;
    
    while( t-- ) {

        int n;
        ll x, ans = 0ll, medics ;
        cin >> n >> x ;
        vll v(n) ;
        for ( ll &i : v )
            cin >> i ;
        sort(v.begin(),v.end()) ;
        vector<bool> vis(n,false) ;
        int itr = 0 ;
        while ( itr < n ) {
            if ( medics == v[itr] ) {
                vis[itr++] = true ;
            }
            while ( medics > v[itr] ) ++itr;
            ++ans ;
            medics>>=1 ;
        }

        for ( bool i : vis )
            if(!i)
                ++ans;

        cout << /*"********************************** ANS = " << */ ans << endl ;
    
    }
    
    return 0 ;   

}
