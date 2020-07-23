def pattern(N,M) :
    n = N
    m = M
    if (not (n&1)) :
        n -= 1
    if (not (m&1)) :
        m -= 1
    p = "BW"
    s1 = "BW"*(m//2)
    l = [s1 for i in range(n) ]
    for i in range(n) :
        if (i&1) :
            l[i] += "W"
        else :
            l[i] += "B"

    #oddxodd prepared

    if ( M%2==0 ) :
        for i in range(n-1) :
            if (i&1) :
                l[i] += "B"
            else :
                l[i] += "W"
        l[n-1] += "B"

    if ( N%2==0 ) :
        s2 = "WB"*(m//2) + "B"
        if ( M%2 == 0 ) :
            s2 += "B"
        l.append(s2)

    return l

def main() :
    t = int(input())
    while (t!=0) :
        t -= 1
        n = input().split()
        m = int(n[1])
        n = int(n[0])
        if ( n==2 and m==2 ) :
            print("BB\nBW")
            continue
        
        l = pattern(n,m)
        for i in l :
            print(i)

main()
