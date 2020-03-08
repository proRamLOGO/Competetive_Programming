import sys 

def main() :

    sys.stdin  = open("input.txt" , "r") ;
    sys.stdout = open("output.txt", "w") ;

    t = int(input()) ;
    
    while ( t ) :
        t -= 1 ;
        
        # Inputs and prep
        n = input().split() 
        m = int(n[1])
        n = int(n[0]) 
        zx = False ; zy = False ;
        x = [] ; y = [] ;
        xpres = {}; ypres = {} ;

        xin = input().split() 
        for i in range(n) :
            x.append(int(xin[i]))
            xpres[x[-1]] = True ;

        yin = input().split() 
        for i in range(m) :
            y.append(int(yin[i]))
            ypres[y[-1]] = True ;
            
        x.sort() ;
        y.sort() ;

        if ( x[0] < 0 and x[-1] > 0 ) : zx = True ;
        if ( y[0] < 0 and y[-1] > 0 ) : zy = True ;

        # Solution ;
        ans = 0 ;

        ''' 
        # Derivation 
        X = xi
        a = yj
        b = yk
        (a + b)^2 == 2i^2 + a^2 + b^2 
        => i^2 == a.b 
        OR
        => a == i && b = 0 
        '''

        # First w.r.t. X Axis

        if (zy) :
            for i in range(n) :
                X = x[i]*x[i] ;
                for j in range(m) :
                    if ( y[j]>=0 ) :
                        break 
                    a = -1*y[j] ;
                    b = X//a ;                
                    if ( a*b == X ) :
                        if ( b in y ) :
                            ans += 1 ;
        
        # Second w.r.t. Y Axis

        if (zx) :
            for i in range(m) :
                Y = y[i]*y[i] ;
                for j in range(n) :
                    if ( x[j]>=0 ) :
                        break 
                    a = -1*x[j] ;
                    b = Y//a ;                
                    if ( a*b == Y ) :
                        if ( b in x ) :
                            ans += 1 ;

        # Including Right Traingles ANGLED AT ORIGIN
        if ( 0 in y and 0 in x ) :
            ans += (n-1)*(m-1) ;
        elif ( 0 in x ) :
            ans += (n-1)*(m) ;
        elif ( 0 in y ) :
            ans += (n)*(m-1) ;

        print(ans) 


main() ;
