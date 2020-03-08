from numpy import datetime64
import sys

def strdate( year, month, day ) :
    s = str(year)+"-02-"
    if ( len(str(day)) < 2 ) :
        s += "0"
    s += str(day)
    return s

def day_of_week_num(dts):
    return (dts.astype('datetime64[D]').view('int64') - 4) % 7

def isleap(y) :
    return ( (y % 4 == 0 and y % 100 != 0) or y % 400 == 0 ) 

def countofcollisions(a,b) :

#     l = []
    ans = 0 
    b += 1
    # 7th feb is friday
    last = 0
    for i in range(a,b) :
        ndate = strdate(i,2,7)
        ndate = datetime64(ndate)
        if ( day_of_week_num(ndate) == 4 ) :
#             l.append(i-last)
#             print(7,"  :  ",i, "      ", i-last)
            last = i
            ans += 1
        if (not isleap(i)) : # not a leap yar
            ndate = strdate(i,2,6)
            ndate = datetime64(ndate)
            if ( day_of_week_num(ndate) == 4 ) :
#                 l.append(i-last)
#                 print(6,"  :  ",i, "      ", i-last)
                last = i
                ans += 1
        
    
#     print(l[2:])
#     repeator(l)
    
    return ans

def main() :
    
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
    # print("he") ;
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
