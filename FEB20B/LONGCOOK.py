from datetime import *
import sys 

MAXYEAR = 1000000

def isleap(y) :
    return ( (y % 4 == 0 and y % 100 != 0) or y % 400 == 0 ) 

def countofcollisions(a,b) :

    ans = 0 
    b += 1
    # 7th feb is friday
    for i in range(a,b) :
        ndate = date(i,2,7)
        if ( ndate.isoweekday() == 5 ) :
            #print(i)
            ans += 1

    # 6th feb is friday
    for i in range(a,b) :
        if (not isleap(i)) : # not a leap yar
            ndate = date(i,2,6)
            if ( ndate.isoweekday() == 5 ) :
                #print(i)
                ans += 1
    
    return ans

def main() :

    sys.stdin = open("input.txt","r") 
    sys.stdout = open("output.txt","w") 

    t = int(input()) 
    
    while ( t > 0 ) :
        t -= 1
        start_m = input().split()
        start_y = int(start_m[1])
        start_m = int(start_m[0])
        end_m = input().split()
        end_y = int(end_m[1])
        end_m = int(end_m[0])
        
        if start_m > 2 :
            start_y += 1 
        if end_m == 1 :
            end_y -= 1 
            
        print(countofcollisions(start_y,end_y))

main()