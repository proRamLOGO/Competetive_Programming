#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

void subsequences( string s, string subseq, unordered_map<string,int> &ss, int &ans ) {

    if ( s.size() == 0 ) {
        ++ss[subseq] ;
        if ( ss[subseq] > 1 and subseq.size() > ans ) 
            ans = subseq.size() ;
        return ;
    }

    subsequences( s.substr(1), subseq, ss, ans ) ;
    subsequences( s.substr(1), subseq+s[0], ss, ans ) ;
    
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
        
        int n; string s ;
        cin >> n >> s ;
        int ans = 0 ;
        unordered_map<string,int> ss ;
        subsequences( s, "", ss, ans ) ;
        cout << ans << endl ;

    }

    return 0 ;

}