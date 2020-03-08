import sys
m = 1000000007

def modInverse(a) : 
    g = gcd(a, m)
    return power(a, m - 2, m) 

def power(x, y, m) : 
    if (y == 0) : 
        return 1
    p = power(x, y // 2, m) % m 
    p = (p * p) % m 
    if(y % 2 == 0) : 
        return p  
    else :  
        return ((x * p) % m) 
  
def gcd(a, b) : 
    if (a == 0) : 
        return b 
    return gcd(b % a, a) 

def main() :
    
    # 866666673
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

    t = int(input())

    ans = []

    for T in range(t) :
        n = int(input())
        s = input()
        ec = 0
        preo = [0]
        prec = [0]
        for i in s :
            preo.append(preo[-1])
            prec.append(prec[-1])
            if ( i == "(" ) :
                preo[-1] += 1
            if ( i == ")" ) :
                prec[-1] += 1
        for i in range(n) :
            for y in range(i+1,n+1) :
                ss = s[i:y]
                no = 0
                nc = 0
                for k in ss :
                    if ( k == "(" ) :
                        no+=1
                    if ( k == ")" ) :
                        nc+=1
                    if ( nc > no ) :
                        ec += 1
                        nc -= 1
                        no += 1


        fo = n*(n-1)//2 + n
        ans.append([ec,fo,(ec*modInverse(fo))%m]) 

    for i in ans :
        print(i)

main()
