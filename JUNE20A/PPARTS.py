# // Author: proRam
# // Name: Shubh Bansal
# // Dated: June 6, 2020
# // Question: https://www.codechef.com/JUNE20A/problems/PPARTS


import sys
sys.stdin = open('JUNE20A/input.txt', 'r') 
sys.stdout = open('JUNE20A/output.txt', 'w')

M = 998244353

def solve( coins, amount, limit, dp, s ) :

    if ( dp[amount][limit]!=-1 ) :
        return dp[amount][limit]

    if ( amount == 0 ) :
        # print(amount,s)
        return 1
        dp[amount][limit] = 1 
        return dp[amount][limit]

    ans = 0

    # print('getting answer of ',amount)

    # print(coins)

    for i in range(limit) :
        if coins[i][0] <= amount and coins[i][1] > 0 :
            # print('using',coins[i][0],'to make',amount)
            coins[i][1] -= 1
            ans = ( ans + solve( coins, amount-coins[i][0], i+1, dp, s+' - '+str(coins[i][0]) )%M ) %M
            coins[i][1] += 1

    dp[amount][limit] = ans 
    # print(*dp,'\n',sep='\n')
    return ans
            
    

def main() :

    n,q = list(map(int,input().split()))
    coins = [ list(map(int,input().split())) for _ in range(q) ] #( val,freq )
    coins.sort()

    for i in range(1,n+1) :
        dp = [ [-1]*(len(coins)+1) for _ in range(n+1) ]
        a = solve(coins,i,len(coins),dp,str(i))
        print(a,sep=' ')


main()