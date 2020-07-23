# import sys
# sys.stdin = open('CF_640_D4/input.txt', 'r') 
# sys.stdout = open('CF_640_D4/output.txt', 'w')

t = int(input()) 

for T in range(t) :
    n = int(input())
    l = [ int(i) for i in input().split()]
    a = l[0]
    b = 0
    ar = l[0]
    br = 0
    mov = 1
    l.pop(0)
    while( len(l)!=0 ) :
        if ( mov&1 ) :
            # bob turn
            bn = 0
            while( bn<=ar and len(l)>0 ) : 
                bn += l.pop() ;
            br = bn
            b += bn 
        else :
            an = 0
            while( an<=br and len(l)>0 ) : 
                an += l.pop(0) ;
            ar = an
            a += an
        mov+=1
    print(mov,a,b)

    
