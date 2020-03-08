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

    while( t-- ) {
        
        int n; string s ;
        cin >> n >> s ;

        unordered_map< char, vector< int > > indices ;

        for ( int i = 0 ; i < n ; ++i ) {
            char ch = s[i] ;
            if ( indices.find(ch) == indices.end() ) {
                vector<int> v(1) ;
                v[0] = i ;
                indices[ch] = v ;
            } else {
                indices[ch].push_back(i) ;
            }
        }

        int k = 0 ;

        for ( auto K : indices ) {
            vector< int > v = K.second ;
            for ( int i = 1 ; i < v.size() ; ++i ) {
                int l = v[i-1], r = v[i] ;
                k = max( k, (l + n - r) ) ;
            }
        }

        cout << k << endl ;
        
    }

    return 0 ;

}