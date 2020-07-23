#include <iostream>

using namespace std;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("2_input.txt","r", stdin) ;
    freopen("output.txt","w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr) ;

    int t;
    cin >> t ;
    for ( int T = 1 ; T <= t ; ++T ){
        string s ;
        cin >> s ;
        if ( s=="AB." or s=="A.B" ) {
            cout << "Case #"<< T << ": Y\n";
            continue ;
        }
        int dot=0,b=0 ;
        for ( int i = 1 ; i < s.length() ; ++i ) {
            dot += (s[i]=='.') ;
            b += (s[i]=='B') ;
            if ( b>=2 and dot>=1 )
                break ;
        }

        cout << "Case #"<< T << ( (b>1 and dot ) ? ": Y" : ": N") ;
        if (t!=T) cout << '\n' ;

    }
}
