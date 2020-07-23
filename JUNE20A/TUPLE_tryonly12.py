# // Author: proRam
# // Name: Shubh Bansal
# // Dated: June 6, 2020
# // Question: https://www.codechef.com/JUNE20A/problems/TTUPLE

import sys
sys.stdin = open('JUNE20A/input.txt', 'r') 
sys.stdout = open('JUNE20A/output.txt', 'w')

class Tuple(object) :
    def __init__(self) :
        self.f, self.s, self.t = None, None, None
    def __str__(self) :
        return (self.f, self.s, self.t)

str,tar = Tuple(),Tuple() ;
select2 = [3,5,6] ;
select1 = [1,2,4] ;
sixinit = [None]*6

# // For Answer 1 - op1 ================================================================================

def op1_0() :
    # // only 1 element tranform needed

    # // p <---x----> a
    # // q .......... b
    # // r .......... c

    for i in select1 :
        
        a,b,c,p,q,r = sixinit

        if ( i==1 ) :
            p = str.f ; a = tar.f ;
            q = str.s ; b = tar.s ;
            r = str.t ; c = tar.t ;
        
        elif ( i==2 ) :
            q = str.f ; b = tar.f ;
            p = str.s ; a = tar.s ;
            r = str.t ; c = tar.t ;
    
        else :
            r = str.f ; c = tar.f ;
            q = str.s ; b = tar.s ;
            p = str.t ; a = tar.t ;
        
        if ( q==b and r==c ) :
            return 1 ;
        
    return 3 ;


def op1_1() :
    # // only 2 element tranform needed

    # // p <---x----> a
    # // q <---x----> b
    # // r .......... c

    a,b,c,p,q,r = sixinit

    for i in select2 :
        
        if ( i==3 ) :
            p = str.s ;
            q = str.t ;
            r = str.f ;
            a = tar.s ;
            b = tar.t ;
            c = tar.f ;
        
        elif ( i==5 ) :
            p = str.f ;
            q = str.t ;
            r = str.s ;
            a = tar.f ;
            b = tar.t ;
            c = tar.s ;
        
        else :
            p = str.f ;
            q = str.s ;
            r = str.t ;
            a = tar.f ;
            b = tar.s ;
            c = tar.t ;

        if ( r!=c ) :
            continue ;

        # // try addition
        if ( a-p == b-q ) :
            return 1 ;
        
        # // try multiplication
        try :
            if ( p!=0 and q!=0 and a%p==0 and b%q==0 and a//p==b//q ) :
                return 1 ;
        except :
            pass

    return 3 ;


def op1_2() :

    # // all 3 element tranform needed
    # // p <---x----> a
    # // q <---x----> b
    # // r <---x----> c

    # // try addition 
    if ( tar.f-str.f == tar.s-str.s and tar.f-str.f == tar.t-str.t ) :
        return 1 ;

    # // try multiplication
    try :
        if ( str.f!=0 and str.s!=0 and str.t!=0 and tar.f%str.f==0 and  tar.s%str.s==0 and  tar.t%str.t==0 and 
            tar.f//str.f==tar.s//str.s and tar.t//str.t==tar.s//str.s ) :
            return 1 ;
    except :
        pass

    return 3 ;

# // For ANswer 2 - op2

def main():

    for _ in range(int(input())) :

        str.f ,str.s ,str.t = list(map(int,input().split()))
        tar.f ,tar.s ,tar.t = list(map(int,input().split()))

        ans = 3

        # // CASE WHEN STR==TAR i.e. ans = 0
        if ( tar.f==str.f and tar.t==str.t and tar.s==str.s ) :
            print(0)
            continue ;

        # // Check if 1 possible solution
        ans = min(min(op1_0(),op1_1()),op1_2());
        if ( ans == 1 ) :
            print(1)
            continue ;
        
        # // Check if 2 possible solution

        # ans = op2_0() ;
        # if ( ans == 2 ) :
        #     print(2)
        #     continue ;
        # ans = op2_1() ;
        # if ( ans == 2 ) :
        #     print(2)
        #     continue ;
        # ans = op2_2() ;
        # if ( ans == 2 ) :
        #     print(2)
        #     continue ;
        # ans = op2_3() ;
        # if ( ans == 2 ) :
        #     print(2)
        #     continue ;
        # ans = op2_4() ;
        # if ( ans == 2 ) :
        #     print(2)
        #     continue ;
        # ans = op2_5() ;
        # if ( ans == 2 ) :
        #     print(2)
        #     continue ;
        # ans = op2_6() ;
        # if ( ans == 2 ) :
        #     print(2)
        #     continue ;
        
        print(2)

    return 0 ;   

main()