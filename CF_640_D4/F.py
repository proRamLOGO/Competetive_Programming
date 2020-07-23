# import sys
# sys.stdin = open('CF_640_D4/input.txt', 'r') 
# sys.stdout = open('CF_640_D4/output.txt', 'w')

t = int(input()) 

for T in range(t) :
    z,zo,o = [ int(i) for i in input().split()]
    ans = ''
    if ( z != 0 ) :
        ans += '0'*(z+1)
    if ( o != 0 ) :
        ans += '1'*(o+1)
    if ( z==0 and o==0 and zo!=0  ) :
        ans = '01'*((zo+1)//2)
        if ( not zo&1 ) :
            ans+='0'
        print(ans)
        continue 
    if ( zo!=0 ) :
        zo-=1
        ans = '01'*(zo//2) + ans
        if ( zo&1 != 0 ) :
            ans = ans[1:]
    print(ans)




    
