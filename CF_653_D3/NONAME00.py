import sys
sys.stdin = open('CF_653_D3/input.txt', 'r') 
sys.stdout = open('CF_653_D3/output.txt', 'w')

for T in range(int(input())) :
    n,k = list(map(int,input().split()))
    l = list(map(int,input().split()))

    for i in range(n) :
        if ( l[i]%k ) :
            l[i] = k-(l[i]%k) 
        else :
            l[i] = 0 ; 
    
    x,f=0,1
    l.sort()    
    s = set()

    for i in range(n) :
        if (l[i]==0) : continue ; 

        if ( l[i] in s ) :
            if ( i!=0 and l[i-1]==l[i] ) :
                ele = l[i]+(k*f) 
                x = max(x,ele)
                s.add(ele) 
                f += 1
        else :
            s.add(l[i]) 
            x = max(x,l[i]) 
        if ( i!=0 and l[i-1]!=l[i] and f!=1 ) :
            f=1 
    x += (x!=0) 
    print(x) 
