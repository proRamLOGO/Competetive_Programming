def main() :
    t = int(input())
    ans = []

    while(t) :
        t -= 1
        n = int(input())
        l = [ int(i) for i in input().split() ]
        l.sort() 
        ol = len(l) ;
        s = ol ;
        i = 0
        while ( i < s ) :
            if ( i != 0 ) :
                if ( l[i]-1 != l[i-1] ) :
                    if ( i==s-1 or l[i+1] != l[i]+1 ) :
                        l.insert(i+1,l[i]+1)
                        s += 1
            elif ( l[1] != l[0]+1 ) :
                l.insert(1,l[0]+1)
                s += 1
                
            i += 1
        ans.append(s-ol) ;
        print(l)

    for i in ans :
        print(i)
            
main()    
    
