#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while ( t-- ) {

        int n ;
        cin >> n ;
        vector< llui > v(n) ;
        for ( int i = 0 ; i < n ; ++i )
            cin >> v[i] ;
    
        for ( int i = 0 ; i < n ; ++i ) {
            cerr << "\ni = " << i << endl ;

            int s = i , e, size = 1 ;

            int j = i ;
            while ( j < n-1 and v[j]+1 == v[j+1] ) {
                ++size ;
                ++j ;
            }
            e = j ;
            cerr << "\nj = " << j << endl ;
            if ( size >= 3 ) {
                if ( i!=0 )
                    cout << ',' ;
                cout << v[s] << "..." << v[e] ;
                i = j ;
            }
            else {
                if ( i!=0 )
                    cout << ',' ;
                cout << v[s];
            }
        }

        cout << endl ;

    }

}
