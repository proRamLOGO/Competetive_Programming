#include <bits/stdc++.h> 
#define MOD 1000000007
using namespace std;

/*def modInverse(a) : 
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
*/

int32_t main() :
    
    # 866666673
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

    t = int(input())
    for T in range(t) :
        n = int(input())
        s = input()
        ec = 0

        for i in range(n) :
            for y in range(i+1,n+1) :
                ss = s[i:y]
                l = ss.count("(")
                if ( l < ( len(ss) - l ) ) :
                    ec += 1

        fo = n*(n+1)//2

        print((ec*modInverse(fo))%m ) 

main()
