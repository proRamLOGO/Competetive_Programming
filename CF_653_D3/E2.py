import sys
sys.stdin = open('CF_653_D3/input.txt', 'r') 
sys.stdout = open('CF_653_D3/output.txt', 'w')

INTMAX = 18446744073709551615

def solve(al,bo,bt,i,k,dp,m,ans,K) :
    
    if ( i>=min(len(al),len(bo))+1 or k>=len(bt)+1 ) :
        return INTMAX
    
    if dp[i][k] != -1 :
        return dp[i][k]

    if i+k == m :
        if i!=k or i!=K:
            dp[i][k] == INTMAX
            return INTMAX
        dp[i][k] = ans 
        return ans
    
    dp[i][k] = INTMAX
    if ( i<min(len(al),len(bo)) ) :
        dp[i][k] = min(dp[i][k], solve(al,bo,bt,i+1,k,dp,m,ans+al[i]+bo[i],K))
    if ( k<len(bt) ) :
        dp[i][k] = solve(al,bo,bt,i,1+k,dp,m,ans+bt[k],K)

    return dp[i][k]



n,m,K = list(map(int,input().split()))
l = [ list(map(int,input().split())) for _ in range(n) ]
al,bo,bt = [],[],[]
for i in l :
    if ( i[1]==1 and i[2]==1 ) :
        bt.append(i[0])
    elif i[1]==1 and i[2]==0 :
        al.append(i[0])
    elif i[1]==0 and i[2]==1 :
        bo.append(i[0])

al.sort()
bt.sort()
bo.sort() 
dp = [ [ -1 ]*(len(bt)+1) for _ in range(min(len(al),len(bo))+1) ]

ans = solve(al,bo,bt,0,0,dp,m,0,K)
if ( ans == INTMAX ) :
    print(-1)
else :
    print(ans)

