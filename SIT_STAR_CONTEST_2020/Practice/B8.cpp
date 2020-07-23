#include <bits/stdc++.h>
using namespace std;
int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s ;
    int n = s.length() ;
    vector<int> u1(26), u2(26) ;
    for ( int i = 0 ; i < n ; ++i )
        ( i&1 ) ? ++u1[s[i]-'A'] : ++u2[s[i]-'A'] ;
    
    bool ans = true ;
    
    // odd length strings
    if ( n&1 ) {
        bool oddutil = false ;
        // ABABC
        // fill up eve pos first
        int itr = 0 ; // inc by2 
        for ( int i = 0 ; ans and i < 26 ; ++i ) {
            char tc = 'A'+i ;
            int &freq = u2[i] ;
            if ( freq&1 and (n/2)&1 ) {
                ans = false ;
                break ;
            }

            if ( freq&1 and !oddutil ) {
                --freq ;
                oddutil = true ;
                s[n>>1] = tc ;
            }

            if ( oddutil and freq&1 ) {
                ans = false ;
            } 
            else {
                while ( freq ) {
                    (--freq)-- ;
                    s[itr] = s[n-itr-1] = tc ;
                    ( ++itr)++ ;
                }
            }
        }
        // A_C_A made
        
        itr = 1 ;
        for ( int i = 0 ; ans and i < 26 ; ++i ) {
            char tc = i+'A' ;
            int &freq = u1[i] ;
            if ( freq&1 and ((n/2)&1^1) ) {
                ans = false ;
                break ;
            }

            if ( freq&1 and !oddutil ) {
                --freq ;
                oddutil = true ;
                s[n>>1] = tc ;
            }

            if ( oddutil and freq&1 ) {
                ans = false ;
            } 
            else {
                while ( freq ) {
                    (--freq)-- ;
                    s[itr] = s[n-itr-1] = tc ;
                    ( ++itr)++ ;
                }
            }
        }
    }

    // even length strings
    else { 
        
        int itr = 0 ;
        // fill up 0,2,4 ;
        for ( int i = 0 ; i < 26 ; ++i ) {
            char tc = i+'A' ;
            int &freq2 = u2[i] ;
            int &freq1 = u1[i] ;

            if ( freq1!=freq2 ) {
                ans = false ;
                break ;
            }
            while ( freq1 ) {
                --freq1 ;
                --freq2 ;
                s[itr] = s[n-1-itr] = tc ;
                ++itr ;
            }
        }

        itr = 1 ;
        // fill up 1,3,5 ;
        for ( int i = 0 ; ans and i < 26 ; ++i ) {
            char tc = i+'A' ;
            int &freq = u1[i] ;
            if ( freq&1 ) {
                ans = false ;
                break ;
            }
            while ( freq ) {
                (--freq)-- ;
                s[itr] = s[n-1-itr] = tc ;
                (++itr)++ ;
            }
        }

    }

    if ( ans ) {
        cout << s << '\n' ;
    } else {
        cout << "NO" << '\n' ;
    }
       
}
