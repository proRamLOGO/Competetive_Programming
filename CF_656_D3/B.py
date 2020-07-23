import sys
sys.stdin = open('CF_656_D3/input.txt', 'r') 
sys.stdout = open('CF_656_D3/output.txt', 'w')
linp = "list(map(int,input().split()))"


def solve(s,l,r,c) :
    # c type = char
    # print(l,' : ',r)
    ch = chr(c)
    if (l==r) :
        if s[l]==ch :
            return 0
        return 1
    
    # find wha part has most c s
    left,right=0,0
    for i in range(l,((l+r)>>1)+1) :
        if s[i]==ch :
            left += 1

    for  i in range( ((l+r)>>1) +1 ,r+1) :
        if s[i]==ch :
            right += 1

    return min( ((r-l+1)>>1)-left + solve(s,((l+r)>>1) +1,r,c+1), ((r-l+1)>>1)-right + solve(s,l,(l+r)>>1,c+1) )


for T in range(int(input()) ) :
    n = int(input())
    s = input() 
    s = 'a'*1000000
    print(solve(s,0,n-1,97))

    