// Author: proRam
// Name: Shubh Bansal
// Dated: June 6, 2020
// Question: https://www.codechef.com/JUNE20A/problems/TTUPLE

#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")
using namespace std;
#ifndef ONLINE_JUDGE 
class Timer { 
    private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now(); cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
#endif

using ll = long long ;
using ull = unsigned long long ;

struct Tuple {

    ll f,s,t ;
    // Tuple( ll x, ll y, ll z ) {
    //     f=x;
    //     s=y;
    //     t=z;
    // }

};

Tuple str,tar ;
int select2[] = {3,5,6} ;
int select1[] = {1,2,4} ;

// For Answer 1 - op1
int op1_0() {
    // only 1 element tranform needed

    // p <---x----> a
    // q .......... b
    // r .......... c

    for ( int i : select1 ) {
        
        ll a,b,c,p,q,r ;

        if ( i==1 ) { 
            p = str.f ; a = tar.f ;
            q = str.s ; b = tar.s ;
            r = str.t ; c = tar.t ;
        } 
        else if ( i==2 ) { 
            q = str.f ; b = tar.f ;
            p = str.s ; a = tar.s ;
            r = str.t ; c = tar.t ;
        } 
        else { 
            r = str.f ; c = tar.f ;
            q = str.s ; b = tar.s ;
            p = str.t ; a = tar.t ;
        }

        if ( q==b and r==c ) {
            return 1 ;
        }
        
    }

    return 3 ;

}

int op1_1() {
    // only 2 element tranform needed

    // p <---x----> a
    // q <---x----> b
    // r .......... c

    ll a,b,c,p,q,r ;

    for ( int i : select2 ) {
        
        if ( i==3 ) {
            p = str.s ;
            q = str.t ;
            r = str.f ;
            a = tar.s ;
            b = tar.t ;
            c = tar.f ;
        }
        else if ( i==5 ) {
            p = str.f ;
            q = str.t ;
            r = str.s ;
            a = tar.f ;
            b = tar.t ;
            c = tar.s ;
        }
        else {
            p = str.f ;
            q = str.s ;
            r = str.t ;
            a = tar.f ;
            b = tar.s ;
            c = tar.t ;
        }

        if ( r!=c ) 
            continue ;

        // try addition
        if ( a-p == b-q )
            return 1 ;
        
        // try multiplication
        if ( p!=0 and q!=0 and a%p==0 and b%q==0 and a/p==b/q )
            return 1 ;
        
    }

    return 3 ;

}

int op1_2() {

    // all 3 element tranform needed
    // p <---x----> a
    // q <---x----> b
    // r <---x----> c

    // try addition 
    if ( tar.f-str.f == tar.s-str.s and tar.f-str.f == tar.t-str.t )
        return 1 ;

    // try multiplication
    if ( str.f!=0 and str.s!=0 and str.t!=0 and tar.f%str.f==0 and  tar.s%str.s==0 and  tar.t%str.t==0 and 
         tar.f/str.f==tar.s/str.s and tar.t/str.t==tar.s/str.s )
        return 1 ;

    return 3 ;
}

// For ANswer 2 - op2

int op2_0() {

    // p <---x---> a
    // q <---x---> b
    // r <---y---> c
    
    // we assume 3 is the answer
    ll a,b,c,p,q,r ;

    for ( int i : select2 ) {
        
        if ( i==3 ) {
            p = str.s ;
            q = str.t ;
            r = str.f ;
            a = tar.s ;
            b = tar.t ;
            c = tar.f ;
        }
        else if ( i==5 ) {
            p = str.f ;
            q = str.t ;
            r = str.s ;
            a = tar.f ;
            b = tar.t ;
            c = tar.s ;
        }
        else {
            p = str.f ;
            q = str.s ;
            r = str.t ;
            a = tar.f ;
            b = tar.s ;
            c = tar.t ;
        }

        // 1. +x, (+y / *y)
        if ( a-p==b-q )
            return 2 ;

        // 2. *x, (+y / *y)
        if ( p!=0 and q!=0 and a%p==0 and b%q==0 and a/p==b/q )
            return 2 ;

    }

    return 3 ;

}

int op2_1() {

    // p <---x---><---y---> a
    // q <---x---><---y---> b
    // r .........<---y---> c
    
    ll a,b,c,p,q,r ;

    for ( int i : select2 ) {
        
        if ( i==3 ) {
            p = str.s ;
            q = str.t ;
            r = str.f ;
            a = tar.s ;
            b = tar.t ;
            c = tar.f ;
        }
        else if ( i==5 ) {
            p = str.f ;
            q = str.t ;
            r = str.s ;
            a = tar.f ;
            b = tar.t ;
            c = tar.s ;
        }
        else {
            p = str.f ;
            q = str.s ;
            r = str.t ;
            a = tar.f ;
            b = tar.s ;
            c = tar.t ;
        }

        // 1. operation reverse enginnering ****************************************************************
        // r reaches c by addition
        if (true) {
            ll diff = c-r ;
            ll midp_req = a-diff ;
            ll midq_req = b-diff ;

                // 1.1 check if we can reach midp and midq by addition
                ll pjump = midp_req - p ;
                ll qjump = midq_req - q ;
                if ( pjump == qjump ) {
                    return 2 ;
                }

                // 1.2 check if we can reach midp and midq by multiplication
                if ( p!=0 and midp_req%p==0 and q!=0 and midq_req%q==0 ) {
                    pjump = midp_req / p ;
                    qjump = midq_req / q ;
                    if ( pjump == qjump ) {
                        return 2 ;
                    }
                }
        }

        // **************************************************************** checking 1 ends 

        // 2. operation reverse enginnering ****************************************************************
        // r reaches c by multiplication

        if ( r!=0 and c%r==0 ) {

            ll cjump = c/r ;
            if ( cjump!=0 and a%cjump==0 and b%cjump==0 ) {
                ll midp_req = a/cjump ;
                ll midq_req = b/cjump ;

                // 2.1 Reach from p,q to midp, midq by addition
                if ( midp_req-p == midq_req-q ) {
                    return 2 ;
                }

                // 2.2 Reache from p,q midwy by multiplication
                if ( p!=0 and midp_req%p==0 and q!=0 and midq_req%q==0 ) {
                    ll pjump = midp_req / p ;
                    ll qjump = midq_req / q ;
                    if ( pjump == qjump ) {
                        return 2 ;
                    }
                }
            }
        }

        // **************************************************************** checking 2 ends 
    }

    return 3 ;

}

int op2_2() {

    // p <---x---> a
    // q <---y---> b
    // r ......... c
    
    // we assume 3 is the answer
    ll a,b,c,p,q,r ;

    for ( int i : select2 ) {
        
        if ( i==3 ) {
            p = str.s ;
            q = str.t ;
            r = str.f ;
            a = tar.s ;
            b = tar.t ;
            c = tar.f ;
        }
        else if ( i==5 ) {
            p = str.f ;
            q = str.t ;
            r = str.s ;
            a = tar.f ;
            b = tar.t ;
            c = tar.s ;
        }
        else {
            p = str.f ;
            q = str.s ;
            r = str.t ;
            a = tar.f ;
            b = tar.s ;
            c = tar.t ;
        }

        if ( r==c ) {
            return 2 ;
        }

    }

    return 3 ;

}

int op2_3() {

    // p <---x---><---y---> a
    // q .........<---y---> b
    // r .........<---y---> c
    
    // we assume 3 is the answer
    ll a,b,c,p,q,r ;

    for ( int i : select2 ) {
        
        if ( i==3 ) {
            p = str.s ;
            q = str.t ;
            r = str.f ;
            a = tar.s ;
            b = tar.t ;
            c = tar.f ;
        }
        else if ( i==5 ) {
            p = str.f ;
            q = str.t ;
            r = str.s ;
            a = tar.f ;
            b = tar.t ;
            c = tar.s ;
        }
        else {
            p = str.f ;
            q = str.s ;
            r = str.t ;
            a = tar.f ;
            b = tar.s ;
            c = tar.t ;
        }
 
        // 1. try +y       
        if ( b-q == c-r ) {
            return 2 ;
        }

        // 2. try *y 
        if ( r!=0 and q!=0 and b%q==0 and c%r==0 and b/q==c/r ) {
            return 2 ;
        }
    }

    return 3 ;

}

int op2_4() {

    // p <---x---><---y---> a
    // q <---x---><---y---> b
    // r <---x---><---y---> c
    
    // +x, *y
    // *x, +y // div + mod
    
    // we assume 3 is the answer
    ll a,b,c,p,q,r ;

    for ( int i : select2 ) {
        
        if ( i==3 ) {
            p = str.s ;
            q = str.t ;
            r = str.f ;
            a = tar.s ;
            b = tar.t ;
            c = tar.f ;
        }
        else if ( i==5 ) {
            p = str.f ;
            q = str.t ;
            r = str.s ;
            a = tar.f ;
            b = tar.t ;
            c = tar.s ;
        }
        else {
            p = str.f ;
            q = str.s ;
            r = str.t ;
            a = tar.f ;
            b = tar.s ;
            c = tar.t ;
        }
 
        // 1. 
        // px + y = a --1
        // qx + y = b --2
        // rx + y = c --3
        // 

        // 5  x10 50  +3 53
        // 10 x10 100 +3 103
        // 20 x10 200 +3 203
        
        if ( p!=0 and q!=0 and r!=0 and a/p==b/q and a/p==c/r and a%p==b%q and a%p==c%r ) {
            return 2 ;
        }

        // 2.
        // (p+x)y = a => py + y = a
        // (q+x)y = b => qy + y = b
        // (r+x)y = c => ry + y = c
        // same as above
        // p + _ * _ + _ * _ = a
        // q + _ * _ + _ * _ = b
        // r + _ * _ + _ * _ = c

    }

    return 3 ;

}

int op2_5() {

    // p <---x--->......... a
    // q <---x---><---y---> b
    // r .........<---y---> c

        // 1 +2     - 3
        // 2 +2 x2  - 8
        // 3    x2  - 6
    
    // we assume 3 is the answer
    ll a,b,c,p,q,r ;

    for ( int i : select2 ) {
        
        if ( i==3 ) {
            p = str.s ;
            q = str.t ;
            r = str.f ;
            a = tar.s ;
            b = tar.t ;
            c = tar.f ;
        }
        else if ( i==5 ) {
            p = str.f ;
            q = str.t ;
            r = str.s ;
            a = tar.f ;
            b = tar.t ;
            c = tar.s ;
        }
        else {
            p = str.f ;
            q = str.s ;
            r = str.t ;
            a = tar.f ;
            b = tar.s ;
            c = tar.t ;
        }
    
        // 1. try to reach c from r by addition
        ll diff = c-r ;
        ll midq = b-diff ;
        
            // 1.1 try to reahc midway by addition
            // covered
            
            // 1.2 try to reach midway by multiplication
            if ( p!=0 and q!=0 and a%p==0 and midq%q==0 and a/p==midq/q )
                return 2 ;

        // 2. try to reach c from r by multiplication
        if ( r!=0 and c%r == 0 ) {
            ll cjump = c/r ;
            if ( b%cjump!=0 )
                continue ;

            ll qmid = b/cjump ;

            // 2.1 try to reach midway by multiplication
            if (  p!=0 and q!=0 and a%p==0 and qmid%q==0 and a/p==qmid/q ) {
                return 2 ;
            }
            // 2.2 try to reach midway by addition
            if ( a-p == qmid-q ) {
                return 2 ;
            }

        }

    }
 
    return 3 ;

}

int op2_6() {

    // p <---x---><---y---> a
    // q .........<---y---> b
    // r .................. c

    // we assume 3 is the answer
    ll a,b,c,p,q,r ;

    for ( int i : select2 ) {
        
        if ( i==3 ) {
            p = str.s ;
            q = str.t ;
            r = str.f ;
            a = tar.s ;
            b = tar.t ;
            c = tar.f ;
        }
        else if ( i==5 ) {
            p = str.f ;
            q = str.t ;
            r = str.s ;
            a = tar.f ;
            b = tar.t ;
            c = tar.s ;
        }
        else {
            p = str.f ;
            q = str.s ;
            r = str.t ;
            a = tar.f ;
            b = tar.s ;
            c = tar.t ;
        }

        if (r!=c)
            continue ;

        // 1. try to reach b from q by addition
        ll diff = b-q ;
        ll midp = a-diff ;
        
            // 1.1 try to reach midway by ADDITION
            // ===== ALREADY COVERED ========

            // 1.2 try to reach midway by multiplication
            if ( p!=0 and midp%p == 0 )
                return 2 ;

        // 2. try to reach midway by multiplication
        if ( b%q!=0 )
            continue ;

        ll jump = b/q ;
        
            // 2.1 try to reach midway by multiplication
            if ( p!=0 and jump%p == 0 )
                return 2 ;
            
    }

    return 3 ;
}



int32_t main(int argc, char** argv) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    int t ;
    ull tom ;
    cin >> t ;
    while ( t-- ) {

        cin >> str.f >> str.s >> str.t ;
        cin >> tar.f >> tar.s >> tar.t ;

        int ans = 3 ;

        // CASE WHEN STR==TAR i.e. ans = 0
        if ( tar.f==str.f and tar.t==str.t and tar.s==str.s ) {
            cout << 0 << '\n' ;
            continue ;
        }

        // Check if 1 possible solution
        ans = min(min(op1_0(),op1_1()),op1_2());
        if ( ans == 1 ) {
            cout << 1 << '\n' ;
            continue ;
        }



        // Check if 2 possible solution

        ans = op2_0() ;
        if ( ans == 2 ) {
            cout << 2 << '\n' ;
            continue ;
        }
        ans = op2_1() ;
        if ( ans == 2 ) {
            cout << 2 << '\n' ;
            continue ;
        }
        ans = op2_2() ;
        if ( ans == 2 ) {
            cout << 2 << '\n' ;
            continue ;
        }
        ans = op2_3() ;
        if ( ans == 2 ) {
            cout << 2 << '\n' ;
            continue ;
        }
        ans = op2_4() ;
        if ( ans == 2 ) {
            cout << 2 << '\n' ;
            continue ;
        }
        ans = op2_5() ;
        if ( ans == 2 ) {
            cout << 2 << '\n' ;
            continue ;
        }
        ans = op2_6() ;
        if ( ans == 2 ) {
            cout << 2 << '\n' ;
            continue ;
        }
        
        cout << 3 << '\n' ;

    }

    cout << endl ;

    return 0 ;   

}
