#include <bits/stdc++.h>
#define llui long long unsigned int 
#define li long int 

using namespace std ;
 
int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    li n ;
    cin >> n ;
    vector< pair< llui, llui > > v(n) ;

    for ( li i = 0 ; i < n ; ++i ) {
        llui x ;
        cin >> x ;
        v[i] = make_pair(x,1) ;
    }
    for ( li i = 0 ; i < n ; ++i ) {
        llui x ;
        cin >> x ;
        v[i].second = x ;
    }

    sort( v.begin(), v.end() ) ;

    // for ( auto i : v ) {
    //     cout << i.first <<' ' << i.second << endl ;
    // }

    li ans = 0 ;

    for ( li i = 0 ; i < n ; ++i ) {
        li lo = i+1 ;
        li hi = n-1 ;
        li p = n ; 
        while ( hi >= lo ) {
            li mid = (lo+hi)/2 ;
            if ( v[i].first+v[mid].first > v[i].second+v[mid].second ) {
                p = mid ;
                hi = mid-1 ;
            } else {
                lo = mid+1 ;
            }
        }
        
        ans += n-p ;
    }

    cout << ans << endl ;

}
