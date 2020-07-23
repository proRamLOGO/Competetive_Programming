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
    
    for ( int T = 1 ; T <= t ; ++T ) {
        
        // Code here
        string s ;
        cin >> s ;
        string ans ;
        s = "0" + s + "0" ;
        
        for ( int i = 1 ; i < s.size() ; ++i ) {

            int n = s[i]-s[i-1] ;
            string b ;
            if ( n < 0 ) {
                b = string(-n,')') ;
            } else {
                b = string(n,'(') ;
            }
            ans += b ;
            if ( i!=s.size()-1 ) ans += s[i] ;
            
        }

        cout << "Case #" << T << ": " << ans << endl ;
        
    }
    
}