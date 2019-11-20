#include <bits/stdc++.h>
#define lli long long int 

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n ;
    vector< int > a ;
    vector< vector< int > > table(n+1,a) ;

    for ( auto i = 0 ; i < 2*n ; i+=2 ) {

        cout << endl << i+1 << ' ' << i+2 ;
        int x, y ;

        string s ;
        cin >> s ;
        if ( s == "MATCH" )
            continue ;

        x = s[0]-'0' ;
        cin >> y ;
        table[x].push_back(i+1) ;
        table[y].push_back(i+2) ;

    }
    cout << endl ;
    /* for ( auto i = 0 ; i < table.size() ; ++i ) {
        cout << i << " : " ;
        for ( auto y : table[i] )
            cout << y << ' ' ;
        cout << endl ;
    } */
    for ( auto i = 0 ; i < table.size() ; ++i ) {
        //cout << i << " : " ;
        for ( auto y = 0 ; y < table[i].size() ; y+=2 ) {
            cout << table[i][y] << ' ' << table[i][y+1] << endl  ;
            string s ;
            cin >> s ;
        }
    }
    cout << -1 << endl ;


    
/*
5
3,4,3,4,1,2,5,5,1,2
*/

}
