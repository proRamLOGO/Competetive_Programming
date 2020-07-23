import sys
sys.stdin = open('Online1C/input.txt', 'r') 
sys.stdout = open('Online1C/output.txt', 'w')


t = int(input()) 

def abs(x):
    if(x<0) :
        x*=-1
    return x;

for T in range(t) :
    l = input().split()
    catx,caty = -int(l[0]), int(l[1])
    s = l[2]
    m = len(s)
    mx,my = 0,0
    ans = ""

    res = False
    mins = 0 
    for i in range(m) :

        dx = catx - mx 
        dy = caty - my 
        if ( dx==0 and dy==0 ) :
            res = True
            break 
        
        if ( s[i]=='N' ) :
            caty+=1 ;
        if ( s[i]=='S' ) :
            caty-=1 ;
        if ( s[i]=='E' ) :
            catx-=1 ;
        if ( s[i]=='W' ) :
            catx+=1 ;
        # cat moved
        
        # print("Cat moved to ",catx,caty)

        mins+=1

        dx = catx - mx 
        dy = caty - my 
        if ( dx==0 and dy==0 ) :
            res = True
            break 

        if ( abs(dx)==abs(dy) ) :
            if ( i<m-1) :
                if (s[i+1] in 'NS' ) :
                    if ( catx < mx ) :
                        mx -= 1
                    else :
                        mx += 1
                else :
                    # move verti
                    if ( caty < my ) :
                        my -= 1
                    else :
                        my += 1                    

        elif ( abs(dx) > abs(dy) ) :
            # move hori
            if ( catx < mx ) :
                mx -= 1
            else :
                mx += 1
        else :
            # move verti
            if ( caty < my ) :
                my -= 1
            else :
                my += 1


        # print("I moved to ",mx,my)
        # print("Mins elapsed",mins)
        # print("********************************")

        dx = catx - mx 
        dy = caty - my 
        if ( dx==0 and dy==0 ) :
            res = True
            break 

    if ( res ) :
        ans = str(mins)
    else :
        ans = "IMPOSSIBLE"

    print( "Case #%i: %s" %(T+1,ans) )
    # print("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=")