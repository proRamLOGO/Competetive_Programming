import sys
sys.stdin = open('CF_641_D2/input.txt', 'r') 
sys.stdout = open('CF_641_D2/output.txt', 'w')
linp = "list(map(int,input().split()))"


import math as mt 
MAXN = 100001
spf = [0 for i in range(MAXN)] 
def sieve(): 
    spf[1] = 1
    for i in range(2, MAXN): 
        spf[i] = i 
    for i in range(4, MAXN, 2): 
        spf[i] = 2
  
    for i in range(3, mt.ceil(mt.sqrt(MAXN))): 
        if (spf[i] == i): 
            for j in range(i * i, MAXN, i):  
                if (spf[j] == j): 
                    spf[j] = i 
  
def getFactorization(x): 
    ret = {}
    while (x != 1): 
        try :
            ret[spf[x]] += 1
        except :
            ret[spf[x]] = 1
        x = x // spf[x] 
    return ret 

sieve()  

n = int(input())
v = eval(linp)
d = {}
d = getFactorization(v[0])
f = 0
for i in v :
    if ( f==0 ) :
        f=1
        continue
    s = getFactorization(i)
    factors = [ i for i in s if i in d ]
    print(i,factors)
    if (len(factors)==0) :
        break
    for i in factors :
        d[i] = min( d[i], s[i] )
a = 1 
for i in d :
    a *= (i**d[i])
print(a)
