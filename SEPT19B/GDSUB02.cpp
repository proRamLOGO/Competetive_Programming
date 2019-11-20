#include <bits/stdc++.h>
#define llui long long unsigned int
#define M 1000000007

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen("output.txt", "w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k ;
    cin >> n >> k ;
    vector< int > arr(n) ;
    map< int, int > freq;

    for ( auto i = 0 ; i < n ; ++i ) {
        cin >> arr[i];
        ++freq[arr[i]];
    }

    int f = 0 ;
    int prev[9000] = {} ;
    
    map<int,int>::iterator it ;
    for ( it = freq.begin() ; it!=freq.end() ; it++ ) {
        f += it->second ;
        prev[it->first] = it->second ;
    }
    
    int res = f % M ;

    for ( int i = 2 ; i <= k ; ++i ) {
        int cnt = 0, cs = 0 ;

        for ( it = freq.begin() ; it!=freq.end() ; it++ ) {
            cnt = ( cnt%M + prev[it->first]%M ) ;
            cnt %= M ;
            prev[it->first] = ( it->second%M * (f - cnt + 1000000007) % M )  ;
            prev[it->first] %= M ;
            cs = ( cs + prev[it->first] ) % M ;
        }

        res += cs ;
        res %= M ;
        f = cs ;

    }

    cout << res%M << endl;

}