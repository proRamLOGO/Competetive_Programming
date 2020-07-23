# import sys
# sys.stdin = open('input.txt', 'r') 
# sys.stdout = open('output.txt', 'w')

M = 998244353

def subseq(l, i, s, ss): 
    if i == len(l): 
        if len(s)!= 0: 
            ss.append(s)
        else :
            ss.append([0]) 
      
    else: 
        subseq(l, i + 1, s, ss) 
        subseq(l, i + 1, s+[l[i]], ss) 

def f( l ) :
    if ( l[0] == 0 ) :
        return 1 
    me = 1 
    for i in l :
        if ( i==me ) :
            me+=1
    return me


def fastpow( b, e ) :
    if ( e==0 ) :
        return 1
    v = fastpow(b,e//2);
    v = ( v%M * v%M ) %M
    if (e&1) :
        v = ( v%M * b%M ) %M
    return v 

t = int(input()) 

for T in range(t) :
    n = int(input())
    l = list(map(int, input().split()))
    l.sort()
    # subs = []
    # subseq(l,0,[],subs)
    rp = -1
    try :
        rp = l[::-1].index(1) 
    except :
        val = (1+fastpow(2,n))%M 
        print(val)
        continue
    
    rp = len(l) - 1 - rp
    rem = 5-rp-1

    val = fastpow(2,rem) # adding not 1s + phy
    val += fastpow(2,rp+1) # adding only 1s + phy

    ans = fastpow(2) ;
    for i in subs :
        ans = ( ans + f(i)%M ) %M
    print(ans) 

    