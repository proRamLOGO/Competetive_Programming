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

    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    int t;
    cin >> t ;
    
    while( t-- ) {

        int n;
        cin >> n ;
        unordered_map<ll,int> v1, v2 ;
        unordered_set<ll> dict ;

        for ( int i = 0 ; i < n ; ++i ) {
            ll x ;
            cin >> x ;
            // cout << "adding " << x << " to v1\n";
            ++v1[x] ;
            dict.insert(x) ;
        }
        for ( int i = 0 ; i < n ; ++i ) {
            ll x ;
            cin >> x ;
            // cout << "adding " << x << " to v2\n";
            ++v2[x] ;
            dict.insert(x) ;
        }
        // cout << endl << v1.size() << v2.size() << endl ;
        // cout << endl << endl;
        // for ( auto i : dict ) cout << i << ' ' ;
        // cout << endl ;
        
        bool f = 0 ;
        ll mine = LLONG_MAX ;
        vll r1, r2;
        
        for ( ll i : dict ) {
            ll num = i ;
            mine = min(mine,num) ;

            int f1=0,f2=0 ;
            if ( v1.find(num)!=v1.end() ) 
                f1 = v1[num] ;
            if ( v2.find(num)!=v2.end() )
                f2 = v2[num] ;

            if ( (f1+f2)&1 ) {
                cout << -1 << '\n' ;
                f = 1 ;
                break ;
            }

            if ( f2<f1 ) {
                for ( int j = 0 ; j < (f1-f2)>>1 ; ++j )
                    r2.push_back(num) ;
            }
            else if ( f2>f1 ) {
                for ( int j = 0 ; j < (f2-f1)>>1 ; ++j )
                    r1.push_back(num) ;
            }

        }

        if (f)
            continue ;

        sort(r1.begin(),r1.end());
        sort(r2.begin(),r2.end(),greater<ll>()); 

        // cout << endl << v1.size() << v2.size() << endl ;

        // cout << endl << "( " ;
        // for ( int i : r1 ) cout << i << ' ' ;
        // cout <<" )" << endl << "( " ;
        // for ( int i : r2 ) cout << i << ' ' ;
        // cout << " )" << endl ;

        ll ans = 0 ;
        for ( int i = 0 ; i < r1.size() ; ++i ) {
            ans += min( min(r1[i],r2[i]), mine*2ll ) ;
        }

        cout << ans << '\n' ;

    }

    cout << endl ;

    return 0 ;   

}
