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

A,B,C,P,Q,R = 0,0,0,0,0,0

def ansis1( p,q,r,a,b,c ) :

    # // a = b = c 

    ans = 3 ;

    if ( a==b==c ) :
        if ( b==0 ) :
            return 1 ;
        else :
            ans = 2

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


def twoin1(p,a,q,b):
    if p==a or q==b :
        return True

    if a-p == b-q :
        return True

    try :
        if a%p==0 and b%q==0 and a//p==b//q :
            return True
    except :
        pass
	
    return False

def coincide(p,a,q,b,r,c) :
    x,d = b-a, q-p
    try :
        y = a - p*(x//d)
        if r * (x//d) + y == c :
            if ( x%d == 0 and (r+y==c or r*y==c) ):
                return True
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
        
        # try ans = 0
        if (P,Q,R)==(A,B,C) :
            print(0)
            continue 

        # Try ans = 1
        # if (P==A and twoin1(Q,B,R,C)) or (Q==B and twoin1(P,A,R,C)) or (R==C and twoin1(Q,B,P,A)) :
        #     print(1)
        #     continue
        
        # diff = A-P
        # if Q+diff==B and R+diff==C :
        #     print(1)
        #     continue
        # if P!=0 and A%P==0 :
        #     diff = A//P
        #     if  Q*diff==B and R*diff==C :
        #         print(1)
        #         continue
        
        # Try ans = 2
        

        for eqorder in range(6) :

            p,q,r,a,b,c = postulate_eqsys(eqorder)    

            a1 = ansis1( p,q,r,a,b,c )
            if ( a1 == 1 ) :
                print(1)
                break

            d = 0

            # 10
            # 11
            # 11
            if p!=0 and a%p==0 :
                d = a//p
                if twoin1(q*d,b,r*d,c) or twoin1(q*d,b,r,c) or twoin1(q,b,r*d,c) or twoin1(q,b,r,c) :
                    print('dtm')
                    print(2)
                    break
            
            d = a - p
            if twoin1(q+d,b,r+d,c) or twoin1(q+d,b,r,c) or twoin1(q,b,r+d,c) or twoin1(q,b,r,c) :
                print(2)
                break
        
            if coincide(p,a,q,b,r,c) :
                print(2)
                break

        else :

            print(3)

main()

'''
31
1 1 1
4 4 4
1 3 10
10000 3 18979
1 1 0
0 1 1
1 3 10
50 55 20
1 3 10
3 8 12
1 2 3
0 0 0
1 3 6
4 4 10
1 3 10
50 55 12
1 -3 7
5 6 8
2 3 5
7 11 13
5 10 13
53 103 133
1 3 -4
9 9 9
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
2 3 5
7 11 13
-15 7 1
-5  3 2
1 2 3
642812522 -800362287 63216506
479416287 -131377407 -485384906
-347797377 -31924853 174025552
-600464641 65936784 -404338570
-583978841 -41853773 -107403941
-115244701 -675856231 195451001
316770650 191379060 444940068
206615556 896617444 103019380
441909256 -657638099 -551749241
-407126904 -951344732 462148145
321213728 988318111 -289609678
891954866 908693161 588785979
-228359789 325816295 -786646575
-864898099 394695004 -914582447
-150731004 292399 738517704
-748650385 118117751 -819616428
-880331605 -153000204 590463802
-269398161 -824891562 -458682725
-471173780 -471435275 -678892583
'''
