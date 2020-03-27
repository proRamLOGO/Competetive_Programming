#include <bits/stdc++.h>
#define lli long long int 

using namespace std ;
 
bool isPal( string s ) {
    int l=0, r=s.size()-1 ;
    while ( l <= r ) {
        if ( s[l]!=s[r] )
            return false ;
        ++l ; --r;
    }
    return true ;
}

string solve( string s, int l, int r, vector< vector< string > >& dp, bool la, bool ra  ) {

    // if ( dp[l][r] != "-" )
    //     return dp[l][r] ;

    if ( l >= r ) {
        return dp[l][r] = "" ;
    }
    if ( la and ra and s[l]==s[r] ) {
        return dp[l][r] = s[l]+ solve(s,l+1,r-1,dp,la,ra) +s[r] ;
    }

    string s1="", s2="" ;
    if ( la )
        s1 = s[l]+solve(s,l+1,r,dp,1,1) ;
    if ( ra )
        s2 = solve(s,l,r-1,dp,1,1)+s[r] ;

    if ( !isPal(s1) )
        s1 = "" ;
    if ( !isPal(s2) )
        s2 = "" ;

    if ( s1.size() > s2.size() ) 
        return dp[l][r] = s1 ;
    else 
        return dp[l][r] = s2 ;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t ;

    while ( t-- ) {

        string s, ans="" ;
        cin >> s ;
        int l=0, r=s.size()-1 ;

        vector< vector< string> > dp(s.size(),vector< string >(s.size(),"-")) ;
        ans = solve( s, l, r, dp, 1, 1  ) ;

        cout << ans << endl ;

    }

}
