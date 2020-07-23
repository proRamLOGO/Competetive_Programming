import sys
sys.stdin = open('LTIME_83B/input.txt', 'r') 
sys.stdout = open('LTIME_83B/output.txt', 'w')

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


t = int(input()) 

for T in range(t) :
    n = int(input())
    l = list(map(int, input().split()))
    l.sort()
    subs = []
    subseq(l,0,[],subs)
    ans = 0 ;
    for i in subs :
        ans = ( ans + f(i)%M ) %M
    print(ans) 

    