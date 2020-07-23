# // Author: proRam
# // Name: Shubh Bansal
# // Dated: June 6, 2020
# // Question: https://www.codechef.com/JUNE20A/problems/TTUPLE

# /*
# Derivation 
# p * x1   +   y1    =    a
# q * x2   +   y2    =    b
# r * x3   +   y3    =    c
# */

import sys
sys.stdin = open('JUNE20A/input.txt', 'r') 
sys.stdout = open('JUNE20A/output.txt', 'w')

A,B,C,P,Q,R  = 0,0,0,0,0,0

def ansis1( p,q,r,a,b,c ) :

    # // a = b = c = 0
    if ( a==b and b==c and a==c ) :
        if ( b==0 ) :
            return 1 ;
        else :
            return 2

    ans = 3 ;

    # // =================================================================

    # // p <---x----> a
    # // q .......... b
    # // r .......... c

    if ( q==b and r==c ) :
        return 1 ;

    # // =================================================================

    # // p <---x----> a
    # // q <---x----> b
    # // r .......... c

    # // try addition
    if ( a-p == b-q ) :
        if (r==c) :
            return 1;
        else :
            ans = 2

    # // try multiplication
    try :
        if ( p!=0 and q!=0 and a%p==0 and b%q==0 and a//p == b//q ) :
            if (r==c) :
                return 1;
            else :
                ans = 2
    except :
        pass

    # // =================================================================

    # // p <---x----> a
    # // q <---x----> b
    # // r <---x----> c    

    # // try addition
    if ( c-r == a-p and a-p == b-q ) :
        return 1 ;

    # // try multiplication
    try :
        if ( r!=0 and p!=0 and q!=0 and a%p==0 and b%q==0 and c%r == 0 and a//p == b//q and a//p == c//r ) :
            return 1 ;
    except :
        pass

    # // =================================================================

    return ans ;

def try_system1( p,q,r,a,b,c ) :

    # // 01 p + y = a            p.......<--y-->a
    # // 11 qx + y = b           q<--x--><--y-->b
    # // 10 rx = c               r<--x-->.......c

    try :
        if ( r==0 or c%r != 0 ) :
            return False ;
    except :
        return False ;

    x = c//r ;
    y = a-p ;

    f1 = q * x ;
    f2 = f1 + y ;
    
    return ( f2 == b );

def try_system2( p,q,r,a,b,c ) :

    # // 01 (p)y = a
    # // 11 (q+x)y = b
    # // 10 (r+x) = c
                
    try :
        if ( p==0 or a%p != 0 ) :
            return False ;

        y = a//p ;
        x = c-r ;

        f1 = q + x ;
        f2 = f1 * y ;

        return ( f2 == b );
    except :
        return False 

def try_system3( p,q,r,a,b,c ) :

    # // 01 p     + y = a
    # // 11 q + x + y = b
    # // 10 r + x     = c
                
    x = c - r ;
    y = a - p ;
    return ( (q+x+y)==b ) ;

def try_system4( p,q,r,a,b,c ) :

    # // 01 p     * y = a
    # // 11 q * x * y = b
    # // 10 r * x     = c
                
    try :
        if ( r==0 or c%r != 0 or p==0 or a%p!=0 ) :
            return False ;

        y = a//p ;
        x = c//r ;

        f1 = q * x ;
        f2 = f1 * y ;

        return ( f2 == b );
    
    except :
        return False

def try_system5( p,q,r,a,b,c ) :

    # // 01 p + y = a
    # // 11 (qx) + y = b
    # // 11 (rx) + y = c

    # // x = b-y / q = c-y/ r

    try :
        y = a-p 
        if ( q==0 or r==0 or (b-y)%q !=0 or (c-y)%r != 0 ) :
            return False ;

        x2 = (b-y)//q ;
        x3 = (c-y)//r ;

        return ( x2==x3 ) ;
    
    except :
        return False


def try_system6( p,q,r,a,b,c ) :

    # // 01  py  = a
    # // 11 (q+x)y = b
    # // 11 (r+x)y = c
                
    try :
        if ( p==0 or a%p!=0 ) :
            return False ;

        y = a//p ;

        x2 = (b//y) - q ;
        x3 = (c//y) - r ;

        return ( x2==x3 );
    
    except :
        return False

def try_system7( p,q,r,a,b,c ) :

    # // 10 (px) = a
    # // 11 (qx) + y = b
    # // 11 (rx) + y = c
                
    try :
        if ( p==0 or a%p!=0 ) :
            return False ;

        x = a//p ;
        # // y = b-qx

        y2 = b - q*x ;
        y3 = c - r*x ;

        return ( y2==y3 );
    
    except :
        return False

def try_system8( p,q,r,a,b,c ) :

    # // 10 (p+x)  = a
    # // 11 (q+x)y = b
    # // 11 (r+x)y = c
                
    try :

        if ( r==0 or c%r != 0 or p==0 or a%p!=0 ) :
            return False ;

        x = a-p ;
        # // y = b/(q+x)

        if ( (q+x)==0 or (r+x)==0 or b%(q+x)!=0 or c%(r+x)!=0 ) :
            return False ;

        y1 = b//(q+x) ;
        y3 = c//(r+x) ;

        return ( y1==y3 );

    except :
        return False

def try_systemequilibrium1( p,q,r,a,b,c ) :

    # // 11 (p+x)y = a
    # // 11 (q+x)y = b
    # // 11 (r+x)y = c
                
    # // y = a/(p+x)
    # // (a*(q+x))/(p+x) = b
    # // x = (bp - aq) / (a-b)

    try :
        n1 = b*p; n2 = a*q; d = a-b ;
        n = n1-n2 ;
        if ( d==0 or n%d!=0 ) :
            return False

        x = n//d ;
        xd = p+x ;
        if ( xd==0 or a%xd!=0 ) :
            return False
        
        y = a//xd ;

        # // we have x and y

        return ( (r+x)*y == c ) ;

    except :
        return False


def try_systemequilibrium2( p,q,r,a,b,c ) :

    # // 11 (px) + y = a
    # // 11 (qx) + y = b
    # // 11 (rx) + y = c
    
    if ( p==0 or q==0 or r==0 ) :
        return False ;

    try:

        x1 = a//p ;
        y1 = a%p ;
        x2 = b//q ;
        y2 = b%q ;
        x3 = c//r ;
        y3 = c%r ;

        return ( x1==x2 and x2==x3 and y1==y2 and y2==y3 ) ;

    except :
        return False

def postulate_eqsys( eqorder ) :

    global P,Q,R,A,B,C

    if eqorder == 0 :
        return (P,Q,R,A,B,C)
    elif eqorder == 1 :
        return (P,R,Q,A,C,B)
    elif eqorder == 2 :
        return (Q,P,R,B,A,C)
    elif eqorder == 3 :
        return (Q,R,P,B,C,A)
    elif eqorder == 4 :
        return (R,P,Q,C,A,B)
    elif eqorder == 5 :
        return (R,Q,P,C,B,A)


def main() :

    global P,Q,R,A,B,C

    for _ in range(int(input())) :
        
        P,Q,R = list(map(int,input().split()))
        A,B,C = list(map(int,input().split()))

        # // CASE WHEN STR==TAR i.e. ans = 0
        if ( P==A and Q==B and R==C ) :
            print(0)
            continue ;

        ans = 3

        for eqorder in range(6) :
            
            p,q,r,a,b,c = postulate_eqsys(eqorder) 

            temp = min(ans,ansis1(p,q,r,a,b,c)) 
            if ( temp == 2 ) :
                ans = 2
            if ( temp == 1 ) :
                ans = 1
                break

            if ( ans == 2 ) :
                continue

            # // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            # // Try Answer 2.0.1 - px + y = a
            # // 11 = 
            # // 11 = 
            # // 11 = 
            if ( try_systemequilibrium1(p,q,r,a,b,c) ) :
                ans = 2

            # // Try Answer 2.0.2 - (p+x)y = a
            # // 11
            # // 11
            # // 11
            if  ( try_systemequilibrium2(p,q,r,a,b,c) ) :
                ans = 2

            # // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            # // Try Answer 2.1.1 - px + y = a
            # // 01
            # // 11
            # // 10
            if ( try_system1(p,q,r,a,b,c) ) :
                ans = min(ans,2) ;

            # // Try Answer 2.1.2 - (p+x)y = a
            # // 01
            # // 11
            # // 10
            if ( ans>2 and try_system2(p,q,r,a,b,c) ) :
                ans = min(ans,2) ;
            
            # // Try Answer 2.1.3 - p+x+y = a
            # // 01
            # // 11
            # // 10
            if ( ans>2 and try_system3(p,q,r,a,b,c) ) :
                ans = min(ans,2) ;
            
            # // Try Answer 2.1.4 - p*x*y = a
            # // 01
            # // 11
            # // 10
            if ( ans>2 and try_system4(p,q,r,a,b,c) ) :
                ans = min(ans,2) ;
            

            # // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            # // Try Answer 2.2.1 - px + y = a
            # // 10
            # // 11
            # // 11
            if ( try_system5(p,q,r,a,b,c) ) :
                ans = 2
            
            # // Try Answer 2.2.2 - (p+x)y = a
            # // 10
            # // 11
            # // 11
            if ( try_system6(p,q,r,a,b,c) ) :
                ans = 2
            
            # // Try Answer 2.2.3 - px + y = a
            # // 01
            # // 11
            # // 11
            if ( try_system7(p,q,r,a,b,c) ) :
                ans = 2
            
            # // Try Answer 2.2.4 - (p+x)y = a
            # // 01
            # // 11
            # // 11
            if ( try_system8(p,q,r,a,b,c) ) :
                ans = 2
            

            # // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            # // Try Answer 2
            # // 11
            # // 11
            # // 00
            if ( r==c ) :
                ans = 2

            # // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            # // Try Answer 2
            # // reset and set 
            if ( a==b and b==c and c==a ) :
                ans = min(ans,2);

            # // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            
        print(ans)

main()