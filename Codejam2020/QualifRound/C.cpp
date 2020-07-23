#include <bits/stdc++.h>
#define st first
#define en second
#define mt make_tuple
#define llui long long unsigned int
#define allv(v) (v.begin(),v.end())

using namespace std ;

bool cmp( tuple < int, int ,int > t1, tuple < int, int ,int > t2 ) {

    if ( get<1>(t1) == get<1>(t2) ) {
        return get<0>(t1) < get<0>(t2) ;
    }
    return get<1>(t1) < get<1>(t2) ;
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t ;
    cin >> t ;
    
    for ( int T = 1 ; T <= t ; ++T ) {
        
        int n ;
        cin >> n ;
        vector< tuple < int, int ,int > > v(n) ;
        for ( int i = 0 ; i < n ; ++i ) {
            int x, y;
            cin >> x >> y;
            v[i] = mt(y,x,i);
        }

        sort(v.begin(),v.end()) ;
        sort(v.begin(),v.end(),cmp) ;
        

        // for ( auto i : v )
        //     cout << get<1>(i) << ' ' << get<0>(i) << ' ' << get<2>(i) << '\n' ;

        vector< bool > loc(n) ;
        // 0  c, 1 j
        int c = 0, j = 0 ;
        bool flag = true ;

        for ( auto i : v ) {
            // check if c can take
            // cout << c << ' ' << j << endl ;
            if ( get<1>(i) >= c ) {
                c = get<0>(i) ;
                loc[get<2>(i)] = false ;
            } else if ( get<1>(i) >= j  ) {
                j = get<0>(i) ;
                loc[get<2>(i)] = true ;
            } else {
                flag = false ;
                break ;
            }
        }

        cout << "Case #" << T << ": " ;
        
        if ( !flag ) {
            cout << "IMPOSSIBLE" << endl ;
            continue ;
        }

        for ( auto i : loc ) {
            if (i) {
                cout << "J" ;
            } else {
                cout << "C" ;
            }
        }

        cout << endl ;
    }
    
}