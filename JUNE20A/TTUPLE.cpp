// Author: proRam
// Name: Shubh Bansal
// Dated: June 6, 2020
// Question: https://www.codechef.com/JUNE20A/problems/TTUPLE

/*
Derivation 
p * x1   +   y1    =    a
q * x2   +   y2    =    b
r * x3   +   y3    =    c

ll P = str.f, Q = str.s, R = str.t ;
ll A = tar.f, B = tar.s, C = tar.t ;
ll X1 = (P!=0) ? A/P : 1, Y1 = (P!=0) ? A%P : A ;
ll X2 = (Q!=0) ? B/Q : 1, Y2 = (Q!=0) ? B%Q : B ;
ll X3 = (R!=0) ? C/R : 1, Y3 = (R!=0) ? C%R : C ;

cout << P << '*' << X1 << " + " << Y1 << " = " << A << endl ;
cout << Q << '*' << X2 << " + " << Y2 << " = " << B << endl ;
cout << R << '*' << X3 << " + " << Y3 << " = " << C << endl ;

dx = distinct(X1, X2, X3) ;
dy = distinct(Y1, Y2, Y3) ;

if dx is < 3 and dy < 3 and x1 or x3 = 1 and y1 or y3 = 0 ;
then ans is 2 ;

*/

#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")
using namespace std;
#ifndef ONLINE_JUDGE 
class Timer { 
    private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now(); cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
#endif
#define PASS 1;
#define printvec(v) for( auto i : v ) cout << i << ' ' ; cout << endl ;
using ll = long long ;

// struct Tuple {

//     ll f,s,t ;
//     Tuple() {
//         PASS ;
//     }
//     Tuple( ll x, ll y, ll z ) {
//         f=x;
//         s=y;
//         t=z;
//     }

// };

// Tuple str,tar ;
int s2[] = {3,5,6}, s1[] = {1,2,4} ;
ll A,B,C,P,Q,R ;

void select1( int i, ll &p, ll&q, ll&r, ll &a, ll&b, ll&c ) {

    if ( i==0 ) { 
        p = str.f ; a = tar.f ;
        q = str.s ; b = tar.s ;
        r = str.t ; c = tar.t ;
    } 
    else if ( i==1 ) { 
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

    if ( i==0 ) {
        p = str.s ;
        q = str.t ;
        r = str.f ;
        a = tar.s ;
        b = tar.t ;
        c = tar.f ;
    }
    else if ( i==1 ) {
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

void postulate( int i, vector<bool> &v ) {
    v[0] = (i>>2)&1 ;
    v[1] = (i>>1)&1 ;
    v[2] = i&1 ;
}

bool solve( ll &a, ll &x, ll &y, ll &b, bool xf, bool yf ) {

    // ax + y = b

    if ( !xf and !yf ) {
        
        // a_ + _ = b 
        if ( a==0 ) {
            return false ;
        }
        x = b/a ;
        y = b%a ;

    }
    else if ( !xf and xf ) {
        
        // a_ + y = b ;
        // x = ( b - y ) / a 
        ll num = b-a;
        if ( a == 0   or   num%a !=0  ) {
            return false ;
        }
        x = num/a ;

    }
    else if ( xf and !xf ) {
        
        // a + _ = b ;
        y = b-a ;

    }
    else {
        
        return ( a==b ) ;

    }

    return true ;

}

int try_system1( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c, vector<ll> x, vector<ll> y, vector<bool> isx, vector<bool> isy ) {

    bool isv1 = solve(p,x[0],y[0],a,isx[0],isy[0]);
    bool isv2 = solve(q,x[1],y[1],b,isx[1],isy[1]);
    bool isv3 = solve(r,x[2],y[2],c,isx[2],isy[2]);

    if ( !( isv1 && isv2 && isv3 ) ) {
        return -1 ;
    }
    
    cout << P << '*' << x[0] << " + " << y[0] << " = " << A << endl ;
    cout << Q << '*' << x[1] << " + " << y[1] << " = " << B << endl ;
    cout << R << '*' << x[2] << " + " << y[2] << " = " << C << endl ;
                
    int dx = distinct(x[0],x[1],x[2]);
    int dy = distinct(y[0],y[1],y[2]);

    if ( dx == 2 and dy == 2 and ( x[0]==1 or x[2]==1 ) and (y[0]==0 or y[2]==0) )  {
        return 2 ;
}

int32_t main(int argc, char** argv) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    // __init_permutations__() ;

    int t ;
    cin >> t ;

    while ( t-- ) {

        cin >> P >> Q >> R ;
        cin >> A >> B >> C ;

        // CASE WHEN STR==TAR i.e. ans = 0
        if ( P==A and Q==B and R==C ) {
            cout << 0 << '\n' ;
            continue ;
        }

        int ans = 3 ;

        for ( int i = 0 ; i < 8 ; ++i ) {
            for ( int j = 0 ; j < 8 ; ++j ) {

                if (i==7 and j==7)
                    continue ;
                cout << i << " " << j << endl ;
                vector<bool> isx(3), isy(3);

                postulate( i, isx ) ;
                postulate( j, isy ) ;

                printvec(isx) ;
                printvec(isy) ;
                
                cout << "\n************************************\n"  ;
                // form equations
                // qx + y = b 
                // rx + y = c
                
                vector<ll> x(3), y(3) ;
                
                if ( isx[0] ) x[0] = 1 ;
                if ( isx[1] ) x[1] = 1 ;
                if ( isx[2] ) x[2] = 1 ;
                if ( isy[0] ) y[0] = 0 ;
                if ( isy[1] ) y[1] = 0 ;
                if ( isy[2] ) y[2] = 0 ;

                ll a=A, b=B, c=C, p=P, q=Q, r=R ;
                int ans1 = try_system1(p,q,r,a,b,c,x,y,isx,isy) ;
                if ( ans1 == 2 ) {
                    ans = 2 ;
                    break ;
                }


                    
                }
                // cout << "\n************************************\n"  ;

            }
            if ( ans < 3 ) {
                break ;
            }

            cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$n"  ;

        }

        cout << ans << '\n' ;

    }
    cout << endl ;

    return 0 ;   

}


/*
7
1 2 3
3 8 6
3 5 7
6 5 10
8 6 3
9 7 8
0 0 0
0 0 0
0 0 0
1 2 3
7 11 10
0 0 5
1 2 3
4 5 6
*/