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
int s2[] = {3,5,6}, s1[] = {1,2,4} ;


void select1( int i, ll &p, ll&q, ll&r, ll &a, ll&b, ll&c ) {

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
}

void select2( int i, ll &p, ll&q, ll&r, ll &a, ll&b, ll&c ) {

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

}

int distinct( ll a, ll b, ll c ) {

    if ( a==b and b==c )
        return 1 ;
    if ( ( a==b and b!=c ) or ( a==c and c!=b ) or ( b==c and a!=b ) )
        return 2 ;

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

        // CASE WHEN STR==TAR i.e. ans = 0
        if ( tar.f==str.f and tar.t==str.t and tar.s==str.s ) {
            cout << 0 << '\n' ;
            continue ;
        }

        // Derivation 
        // p * x1   +   y1    =    a
        // q * x2   +   y2    =    b
        // r * x3   +   y3    =    c

        ll P = str.f, Q = str.s, R = str.t ;
        ll A = tar.f, B = tar.s, C = tar.t ;
        ll X1 = (P!=0) ? A/P : 1, Y1 = (P!=0) ? A%P : A ;
        ll X2 = (Q!=0) ? B/Q : 1, Y2 = (Q!=0) ? B%Q : B ;
        ll X3 = (R!=0) ? C/R : 1, Y3 = (R!=0) ? C%R : C ;

        // cout << P << '*' << X1 << " + " << Y1 << " = " << A << endl ;
        // cout << Q << '*' << X2 << " + " << Y2 << " = " << B << endl ;
        // cout << R << '*' << X3 << " + " << Y3 << " = " << C << endl ;

        int d = (X1!=1)+(X2!=1)+(X3!=1)+(Y2!=0)+(Y2!=0)+(Y3!=0) ;


        cout << min(3,d -min(1,distinct(X1,X2,X3)-1) -min(1,distinct(Y1,Y2,Y3)-1) ) << '\n' ;

        if (1) {
        // int ans = 2 ;

        
        // // 1. 1 1 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        // if ( dx==1 and dy==1 ) {
        //     ans = (dx!=1)+(dy!=0) ;
        //     goto STOP ;
        // }

        // // 2. 1 2 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        // else if ( dx==1 and dy==2 ) {
        //     for ( int i : s2 ) {
        //         ll p=P,q=Q,r=R,a=A,b=B,c=C ;
        //         select2(i,p,q,r,a,b,c) ;
        //         ll x1 = (p!=0) ? a/p : 1, y1 = (p!=0) ? a%p : a ;
        //         ll x2 = (q!=0) ? b/q : 1, y2 = (q!=0) ? b%q : b ;
        //         ll x3 = (r!=0) ? c/r : 1, y3 = (r!=0) ? c%r : c ;
                
                
        //         // if ( y3 == 0 ) ans = 2 ;
        //         // if ( x1 == 1 ) ans = 2 ;
        //         // if ( y1 == 0 ) ans = 2 ;

        //         if ( x1==1 and y1==0 ) ans = 1 ; 
        //         if ( x1==1 and y3==0 ) ans = 1 ; 

        //         if ( ans==1 )
        //             goto STOP ;

        //     }
        // }

        // // // 3. 1 3 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        // // else if ( dx==1 and dy==3 ) {
        // //     for ( int i : s2 ) {
        // //         ll p=P,q=Q,r=R,a=A,b=B,c=C ;
        // //         select2(i,p,q,r,a,b,c) ;
        // //         ll x1 = (p!=0) ? a/p : 1, y1 = (p!=0) ? a%p : a ;
        // //         ll x2 = (q!=0) ? b/q : 1, y2 = (q!=0) ? b%q : b ;
        // //         ll x3 = (r!=0) ? c/r : 1, y3 = (r!=0) ? c%r : c ;
                
                
        // //         if ( x1 == 1 and y1==0 ) {
        // //             ans = 2 ;
        // //             goto STOP ;
        // //         }

        // //     }
        // // }

        // // 4. 2 1 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        // else if ( dx==2 and dy==1 ) {
        //     for ( int i : s2 ) {
        //         ll p=P,q=Q,r=R,a=A,b=B,c=C ;
        //         select2(i,p,q,r,a,b,c) ;
        //         ll x1 = (p!=0) ? a/p : 1, y1 = (p!=0) ? a%p : a ;
        //         ll x2 = (q!=0) ? b/q : 1, y2 = (q!=0) ? b%q : b ;
        //         ll x3 = (r!=0) ? c/r : 1, y3 = (r!=0) ? c%r : c ;
                
        //         // if ( x1 == 1 ) ans = 2 ;
        //         // if ( x3 == 1 ) ans = 2 ;
        //         // if ( y1 == 0 ) ans = 2 ;

        //         if ( x1==1 and y1==0 ) ans = 1 ; 
        //         if ( x3==1 and y1==0 ) ans = 1 ; 

        //         if ( ans==1 )
        //             goto STOP ;

        //     }
        // }

        // // // 7. 3 1 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        // // else if ( dx==2 and dy==1 ) {
        // //     for ( int i : s2 ) {
        // //         ll p=P,q=Q,r=R,a=A,b=B,c=C ;
        // //         select2(i,p,q,r,a,b,c) ;
        // //         ll x1 = (p!=0) ? a/p : 1, y1 = (p!=0) ? a%p : a ;
        // //         ll x2 = (q!=0) ? b/q : 1, y2 = (q!=0) ? b%q : b ;
        // //         ll x3 = (r!=0) ? c/r : 1, y3 = (r!=0) ? c%r : c ;

        // //         if ( x1==1 and y1==0 ) ans = 2 ; 

        // //         if ( ans==2 )
        // //             goto STOP ;
        // //     }
        // // }
    
        // // // 5. 2 2 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        // // else if ( dx==2 and dy==2 ) {

        // //     for ( int i : s2 ) {
        // //         ll p=P,q=Q,r=R,a=A,b=B,c=C ;
        // //         select2(i,p,q,r,a,b,c) ;
        // //         ll x1 = (p!=0) ? a/p : 1, y1 = (p!=0) ? a%p : a ;
        // //         ll x2 = (q!=0) ? b/q : 1, y2 = (q!=0) ? b%q : b ;
        // //         ll x3 = (r!=0) ? c/r : 1, y3 = (r!=0) ? c%r : c ;

        // //         if ( x1==x2 and x2!=x3 and y1!=y2 and y2==y3 ) {

        // //             if ( x3==1 and y2==0 ) ans = 2 ;
        // //             if ( x3==1 and y1==0 ) ans = 2 ;
        // //             if ( x1==1 and y2==0 ) ans = 2 ;
        // //             if ( x1==1 and y1==0 ) ans = 2 ;

        // //             if ( ans == 2 ) {
        // //                 goto STOP ;
        // //             }

        // //         }
                
        // //         else if ( x1==x2 and x2!=x3 and y1==y2 and y2!=y3 ) {

        // //             if ( x3==1 and y3==0 ) ans = 2 ;
        // //             if ( x3==1 and y1==0 ) ans = 2 ;
        // //             if ( x1==1 and y3==0 ) ans = 2 ;
        // //             if ( x1==1 and y1==0 ) ans = 2 ;

        // //             if ( ans == 2 ) {
        // //                 goto STOP ;
        // //             }

        // //         }

        // //     }
        // // }


        // // // 6. 2 3 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        // // // 8. 3 2
        // // // 9. 3 3
        // else if ( dx+dy>4 or (dx=1 and dy==3)  ) {
        //     ans = 3 ;
        //     goto STOP ;
        // }

        // // ----------------------------------------------------------------
        // STOP:
        // cout << ans << '\n' ;
        1;}
    }
    cout << endl ;

    return 0 ;   

}
