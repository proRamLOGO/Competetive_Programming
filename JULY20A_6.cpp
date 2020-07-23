#include <bits/stdc++.h>
using namespace std;

using ll = long long ;
using ull = unsigned long long ;
using pll = pair<ll, ll> ;
using vll = vector<ll> ;
using vpll = vector<pll> ;
using vvll = vector<vll> ;
using vs = vector<string> ;

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
        
        medics = x ;
        
        vector<bool> available(n,true) ;
        
        for ( int i = 0 ; i < n ; ++i ) {
            if ( medics >= v[i] ) {
                if ( medics <= (v[i]<<1ll) ) {
                    available[i] = false ;
                    ++ans ;
                    medics = (v[i]<<1ll) ;
                }
            } else {
                while ( medics < v[i] ) {
                    ++ans ;
                    medics<<=1ll ;
                }
                available[i] = false ;
                medics = (v[i]<<1ll) ;
                ++ans ;
            }
        }

        for ( bool i : available )
            ans += i ;

        cout << ans << endl ;
    
    }
    
    return 0 ;   

}
