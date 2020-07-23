# import sys
# sys.stdin = open('CF_641_D2/input.txt', 'r') 
# sys.stdout = open('CF_641_D2/output.txt', 'w')
linp = "list(map(int,input().split()))"

t = int(input()) 

def spf(num) :
    # if ( num==2 ): return 2
    for i in range(2,num+1) :
        if ( i*i>num ) :
            break
        if ( num%i == 0 ) :
            return i
    return num

for T in range(t) :
    n,k = eval(linp)
    s = spf(n)
    print(n+s+(k-1)*2)
    