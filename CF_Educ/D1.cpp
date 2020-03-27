#include <bits/stdc++.h>
#define lli long long int 

using namespace std ;
 
string solve( string str ) {
    int n = str.size();  
    bool table[n][n]; 
      
    memset(table, 0, sizeof(table)); 
    int maxLength = 1; 
      
    for (int i = 0; i < n; ++i) 
        table[i][i] = true; 

    int start = 0; 
    for (int i = 0; i < n-1; ++i) 
    { 
        if (str[i] == str[i+1]) 
        { 
            table[i][i+1] = true; 
            start = i; 
            maxLength = 2; 
        } 
    } 
  
    for (int k = 3; k <= n; ++k) 
    { 
        for (int i = 0; i < n-k+1 ; ++i) 
        { 
            int j = i + k - 1; 
            if (table[i+1][j-1] && str[i] == str[j]) 
            { 
                table[i][j] = true; 
  
                if (k > maxLength) 
                { 
                    start = i; 
                    maxLength = k; 
                } 
            } 
        } 
    } 
    return str.substr( start, maxLength ); 
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
        if ( s.size()==1 ) {
            cout << s << endl;
            continue ;
        }

        int l=0, r=s.size()-1 ;
        while ( l <= r and s[l]==s[r] ) {
            ans += s[l] ;
            ++l ;
            --r ;
        }
        string temp = ans ;
        reverse(temp.begin(),temp.end()) ;
        string expt = solve(s.substr(l,r-l+1)) ;
        ans = ans + expt + temp ;
        // cout << s.substr(l,r-l+1) << ' ' ;
        // cout << expt << ' ' << ans << endl ;

        if ( ans.size()==0 )
            ans = s[0] ;

        cout << ans << endl ;

    }

}
