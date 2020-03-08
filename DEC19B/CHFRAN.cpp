#include <bits/stdc++.h>
#define llui long long unsigned int 
#define lli long long  int 
#define lui long unsigned int 
#define M 1000000007
#define MAX 10000
using namespace std ;

int solve( vector< pair< llui, llui > > v, int i, lli right, int size_of_set1 ) {
    if ( i == v.size() ) {
        return -1 ;
    }
    
    int res1, res2, res3 ;
    
    res1 = res2 = res3 = -1 ; 

    // include 
    if ( v[i].second <= right )
        res1 = solve( v, i+1, max(right,(lli)(v[i].second)), size_of_set1+1 ) ;

    // exclude
    res2 = solve( v, i+1, right, size_of_set1 ) ;

    // create
    if (  right != -1 and v[i].first > right ) {
        // cout << v[i].first << " " << v[i].second << endl ;
        res3 = (i - size_of_set1) ; 
        // cout << res3 ;
    }


    if ( res1!=-1 and res2!=-1 and res3 != -1 ) { 
        return min(res1,min(res2,res3)) ;
    } else {
        if ( res1 == -1 )
            if ( res2 == -1 or res3 == -1 )
                return max(res2,res3) ;
            else 
                return min(res2,res3) ;
        else if ( res2 == -1 )
            if ( res1 == -1 or res3 == -1 )
                return max(res1,res3) ;
            else 
                return min(res1,res3) ;
        else if ( res3 == -1 )
            if ( res2 == -1 or res1 == -1 )
                return max(res2,res1) ;
            else 
                return min(res2,res1) ;
    }

    return -1 ;

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

    while( t-- ) {
        
        int n ;
        cin >> n ;
        vector< pair< llui, llui > > v(n) ;

        for ( int i = 0 ; i < n ; ++i ) {
            llui x, y ;
            cin >> x >> y ;
            v[i] = make_pair(x,y) ;
        }

        sort( v.begin(), v.end() ) ;

        cout << solve(v, 0, -1, 0 ) << endl ;

    }

    return 0 ;

}