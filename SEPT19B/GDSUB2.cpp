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
    //int x;
    map< int, int > freq;

    for ( auto i = 0 ; i < n ; ++i ) {
        cin >> arr[i];
        ++freq[arr[i]];
    }

    int f = 0 ;
    vector<int> prev((int)8e3 + 6,0) ;
    
    for ( auto i : freq ) {
        f += i.second ;
        prev[i.first] = i.second ;
    }

    int res = f % M ;

    for ( auto i = 2 ; i < min(k,1300) ; ++i ) {
        int cnt = 0, cs = 0 ;

        for ( auto it : freq ) {
            cnt = ( cnt%M + prev[it.first]%M ) % M ;
            prev[it.first] = ( it.second%M * (f - cnt + M) %M ) %M ;
            cs = ( cs%M + prev[it.first]%M ) % M ;
        }

        res += cs ;
        res %= M ;

    }

    cout << res%M << endl;

}