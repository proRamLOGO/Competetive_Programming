def cntsetbits( n ) :
    cnt = 0 ;
    while ( n != 0 ) :
        cnt+= 1
        n = n&(n-1) ;
    return cnt ;

def rb( n ) :
    n = bin(n)[2:]
    return(len(n) - n.find('1') - 1 )

def rr1( n ) :
    p = rb(n)
    z=(n&1) ;
    n >>= 1 ;
    if (z==1) :
        n |= (z<<p) ;
    return n ;

def rr(bs) :
    num = bs[:-1]
    num = bs[-1] + num
    return num

def main() :
    t = int(input())
    while ( t!=0 ) :
        t -= 1
        a = input().split()
        b = int(a[1])
        a = int(a[0])
        z=1 ;
        limit = 2**(cntsetbits(b)) ;
        limit-=1;
        
        mv = (a^b) ;
        mi = 0 ; cnt = 0 ;
        l = max(len(bin(b))-2,len(bin(a))-2)

        bs = '0'*(l-(len(bin(b))-2)) + bin(b)[2:]
        print(bs)
        while ( cnt <= l ) :
            cnt+=1 ;
            bs = rr(bs) ;        
            print("bs = ",bs)
            b = int(bs,2) ;
            print(a^b)
            if ( (a^b) > mv ) :
                mv = (a^b) ;
                mi = cnt ;
        print(mi,mv)

    return 0 ;

main()
