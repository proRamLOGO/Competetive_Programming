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

    int distinct = freq.size() ;
    int cnt = 0 ;
    for ( auto i : freq ) {
        distinct -= i.second ;
        cout << distinct << ' ' ;
    }
    while ( cnt < n )
        cout << 0 << ' ' ;

}