import sys
sys.stdin = open('CF_639_D2/input.txt', 'r') 
sys.stdout = open('CF_639_D2/output.txt', 'w')

t = int(input()) 

def noc( i ) :
    return (3*( (i*(i+1))//2 ) - i)

def bs( n ) :
    lo,hi = 1,10**5
    ans = -1
    while( hi >= lo ) :
        mid = (lo+hi)//2 
        if ( noc(mid) <= n  ) :
            ans = max(ans,mid)
            lo = mid+1
        else :
            hi = mid-1
    return ans


for T in range(t) :
    # print("================================================")
    n = int(input())
    if ( n==1 ) :
        print(0)
        continue
    # for i in range(1,n) :
    #     print( 3*( (i*(i+1))//2 ) - i, noc(bs(i)) )
    ans = 0
    while( n>1 ) :
        # print(n,noc(bs(n)))
        n -= noc(bs(n))
        ans += 1
    print(ans)

    
