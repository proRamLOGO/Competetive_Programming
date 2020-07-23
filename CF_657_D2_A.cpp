
#include <bits/stdc++.h>
using namespace std;

bool issame(string &s) {
    string dic = "abacaba" ;
    for ( int j = 0 ; j < 7 ; ++j ) 
        if (s[j]!='?' and s[j]!=dic[j]) 
            return false ;
    return true ;
}
int eligible(string &s) { 
    string dic = "abacaba" ;
    int prev = 0 ;
    for ( int i = 0 ; i < s.length()-6 ; ++i ) {
        string samp = s.substr(i,7) ;
        prev += (samp==dic) ;
        if (prev==2)
            return 2 ;
    }
    return prev ;
}

int32_t main(int argc, char** argv) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    int t; 
    cin >> t ;
    while(t--) {
        int n ; string s ;
        cin >> n >> s ;
        string dic = "abacaba" ;
        
        int prev = eligible(s) ;
        
        if ( prev==1 ) {
            for ( auto &i : s )
                if (i=='?')
                    i='e' ;
            cout << "Yes\n" << s <<'\n';
            continue ;
        } else if ( prev>1 ) {
            cout << "No\n" ;
            continue ;
        }

        bool ans = false ;
        for ( int i = 0 ; i < n-6 ; ++i ) {
            string restore = s.substr(i,7) ;
            if (issame(restore)) {
                string news = s ;
                for ( int j = i ; j < i+7 ; ++j ) {
                    news[j] = dic[j-i] ;
                }
                for ( auto &i : news )
                    if (i=='?')
                        i='z' ;
                int cnt = eligible(news) ;
                if (cnt==1) {
                    ans = true ;
                    s = news ;
                    break ;
                }
            }
        }
        if ( ans ) {
            cout << "Yes\n" << s ;
        } else {
            cout << "No" ;
        }
        cout << '\n' ;
    }
    cout << endl ;

    return 0 ;   

}
