#include <bits/stdc++.h>
using namespace std ;

int main() {
    
    string num ;
    cin >> num ;
    num = "00"+num ;

    vector<int> v ;
    
    for ( int i = 0 ; i < 999 ; ++i ) 
        if ( i%8 == 0 )
            v.push_back(i) ;
         
    string ans = "" ;   
    for ( int i = 0 ; i < v.size() ; ++i ) {
        
        string newnum = "", obt = to_string(v[i]) ;
        if ( obt.size()==1 )
            obt = "00"+obt ;
        else if ( obt.size()==2 )
            obt = "0"+obt ;
            
        int cnt = 2, j ;
        
        for ( j = num.size()-1 ; cnt > -1 and j >= 0 ; --j ) {
            if ( num[j] == obt[cnt] ) {
                --cnt ;
            }
        }
        if ( cnt == -1 ) {
            ans = num.substr(0,j+1) + obt ;
            break ;
        }
            
    }
    
    if ( ans.size()==0 ) {
        cout << "NO" << endl ;
    } else {
        int cnt=0;
        while( ans[cnt] == '0' )
            ++cnt ;
        ans = ans.substr(cnt,ans.size()-cnt) ;
        if ( ans.size()==0 )
            ans="0" ;
        cout << "YES\n" << ans << endl ;
    }

}