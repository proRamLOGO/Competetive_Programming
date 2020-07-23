#include <iostream>
#include <stack>

using namespace std;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("3_input.txt","r", stdin) ;
    freopen("output.txt","w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr) ;

    int t;
    cin >> t ;
    for ( int T = 1 ; T <= t ; ++T ){
        string S ;
        cin >> S ;
        cout << "Case #" << T << ": " ;
        if ( S=="0" or S=="1" ) {
            cout << 0 << '\n' ;
        }
        else if ( S=="x" or S=="X" ) {
            cout << 1 << '\n' ;
        } else {
            int ans = 0 ;
            for ( int i = 0 ; i < 2 ; ++i ) {
                string s = S ;
                for ( auto &c : s )
                    if ( c=='x' ) 
                        c = i+'0' ;
                    else if ( c=='X' ) 
                        c = 1-i+'0' ;
            
                // exp finalized now convert to postfix from infix

                stack<char> stk ;
                string postfix = "" ;
                for ( char i : s ) {
                    if ( i=='(' ) 
                        stk.push(i) ;
                    else if ( i==')' ) {
                        while( stk.top()!='(' ) stk.pop() ;
                        stk.pop() ;
                    } else if ( i=='0' or i=='1' ) {
                        postfix += i ;
                    } else {
                        stk.push(i) ;
                    }
                }
                while (!stk.empty()) {
                    postfix += stk.top() ;
                    stk.pop() ;
                }

                // evaluate postfix
                for ( char i : postfix ) {

                    if ( i=='1' or i=='0' ) 
                        stk.push(i) ;
                    else {
                        int op1 = stk.top()-'0' ; stk.pop() ;
                        int op2 = stk.top()-'0' ; stk.pop() ;
                        int res = 0 ;
                        if ( i == '|' )
                            res = op1|op2 ;
                        if ( i == '&' )
                            res = op1&op2 ;
                        if ( i == '^' )
                            res = op1^op2 ;
                        stk.push(res+'0') ;
                    }

                }

                ans += stk.top()-'0' ;
            }

            if ( ans != 1 ) {
                cout << 0 ;
            } else {
                cout << 1 ;
            }
            cout << '\n';

        }
    }
}
