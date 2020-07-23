# import sys
# sys.stdin = open('CF_641_D2/input.txt', 'r') 
# sys.stdout = open('CF_641_D2/output.txt', 'w')
linp = "list(map(int,input().split()))"

t = int(input()) 
for T in range(t) :
    n = int(input())
    v = eval(linp)
    v = [0]+v
    dp = [0]*(n+1)
    dp[-1]=1
    for i in range(n-1,0,-1) :
        for j in range(i+i,n+1,i) :
            if ( v[j]>v[i] ) :
                dp[i] = max(dp[i],dp[j] )
        dp[i]+=1
    
    print(max(dp))