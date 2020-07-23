import sys
sys.stdin = open('input.txt', 'r') 
sys.stdout = open('output.txt', 'w')

M = 998244353
MI = 748683265

def modInverse(a) : 
    g = gcd(a, M)
    return power(a, M - 2) 

def power(x, y) : 
    if (y == 0) : 
        return 1
    p = power(x, y // 2) % M 
    p = (p * p) % M 
    if(y % 2 == 0) : 
        return p  
    else :  
        return ((x * p) % M) 
  
def gcd(a, b) : 
    if ( a > b) :
        return gcd(b,a)
    if (a == 0) : 
        return b 
    return gcd(b % a, a)

def main() :

    t = int(input())
    while ( t!=0 ) :
        t-=1 

        s = input()
        noofh = s.count('#') 
        operators = [] ; # array of arrays
        idx = []

        for i in range(len(s)) :
            if (s[i]==')') : 
                idx.append(i) 
            if ( s[i]=='^' or s[i]=='&' or s[i]=='|' ) :
                operators.append(s[i])
        
        oprnds = [ [1,1,1,1] ] * noofh  # 0, 1, a, A
 
        # eval starts
        for i in idx :
            
            op2 = oprnds[-1] 
            op1 = oprnds[-2]  
            res = [1,1,1,1]  
            
            opr = operators[-1] 

            t2 = ( op2[0] + op2[1] + op2[2] + op2[3] ) % M 
            t1 = ( op1[0] + op1[1] + op1[2] + op1[3] ) % M 

            if ( opr == '^' ) :

                # Perform XOR
                res[1] = ( ( op1[0] * op2[1] ) + ( op1[1] * op2[0] ) + ( op1[2] * op2[3] ) + ( op1[3] * op2[2] ) ) % M 
                res[0] = ( ( op1[0] * op2[0] ) + ( op1[1] * op2[1] ) + ( op1[2] * op2[2] ) + ( op1[3] * op2[3] ) ) % M 
                res[2] = ( ( op1[0] * op2[2] ) + ( op1[1] * op2[3] ) + ( op1[3] * op2[1] ) + ( op1[3] * op2[1] ) ) % M 
                res[3] = ( ( op1[3] * op2[0] ) + ( op1[0] * op2[3] ) + ( op1[1] * op2[2] ) + ( op1[2] * op2[1] ) ) % M

            elif ( opr == '&' ) :

                # Perform AND
                # overflow cechk
                res[0] = ( ( ( ( op2[0] * t1 )%M + op1[0] * t2 )%M - (op1[0] * op2[0])%M + M )%M + ( op1[2] * op2[3] )%M + ( op1[3] * op2[2] )%M + M ) % M 
                res[1] = ( op1[1] * op2[1] ) % M
                res[2] = ( ( op1[2] * op2[2] ) + ( op1[1] * op2[2] ) + ( op1[2] * op2[1] ) ) % M
                res[3] = ( ( op1[3] * op2[3] ) + ( op1[1] * op2[3] ) + ( op1[3] * op2[1] ) ) % M 
            
            elif ( opr == '|' ) :

                # Perform OR
                res[1] = ( ( ( ( op2[1] * t1 )%M + op1[1] * t2 )%M - (op1[1] * op2[1])%M + M )%M + ( op1[2] * op2[3] )%M + ( op1[3] * op2[2] )%M + M ) % M 
                res[0] = ( op1[0] * op2[0] ) % M 
                res[2] = ( ( op1[2] * op2[2] ) + ( op1[0] * op2[2] ) + ( op1[2] * op2[0] ) ) % M 
                res[3] = ( ( op1[3] * op2[3] ) + ( op1[0] * op2[3] ) + ( op1[3] * op2[0] ) ) % M 
            

            oprnds.pop() 
            oprnds.pop() 
            oprnds.append(res) 

            operators.pop()
        # sy = oprnds[-1][0] + oprnds[-1][1] + oprnds[-1][2] + oprnds[-1][3]
        # MI = modInverse(4)
        # print( oprnds[-1][0] , oprnds[-1][1] , oprnds[-1][2] , oprnds[-1][3] )
        # pro it up
        for i in range(noofh) :
            
            oprnds[-1][0] = ( oprnds[-1][0] * MI ) % M 
            oprnds[-1][1] = ( oprnds[-1][1] * MI ) % M 
            oprnds[-1][2] = ( oprnds[-1][2] * MI ) % M 
            oprnds[-1][3] = ( oprnds[-1][3] * MI ) % M 
        

        print( oprnds[-1][0] , oprnds[-1][1] , oprnds[-1][2] , oprnds[-1][3] )

main()