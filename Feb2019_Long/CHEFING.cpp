#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std ;

int main() {

    int t ;
    cin >> t ;


    map< char, bool > check ;
    map< char, int > res ;
    string x = 'abcdefghijklmnopqrstuvwxyz' ;

    for ( auto c : x ) {
        check[c] = 0 ;
        res[c] = 0 ; 
    }

    while ( t-- ) {

        int n ;
        cin >> n ;
        map< char, int > ans(res) ;
        string s ;

        for ( auto i = 0 ; i < n ; ++i ) {

            cin >> s ;
            map< char, bool > mp(check) ;
            
            for ( auto c : s ) {
                if ( mp[c]==0 ) {
                    mp[c] = 1 ;
                    ans[c]++ ;
                }
            }

        }

        int answer = 0 ;

        for ( auto c : ans ) {
            if ( c.second == n )
                answer++ ;
        }

        cout << answer << endl ;


    }

}