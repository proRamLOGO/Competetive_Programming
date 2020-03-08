DB = [5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 1, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 6, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6, 5, 1, 5, 5, 1, 5, 6]

l = len(DB)

def searchh( x, e ): 
    if x <= 3 :
        return -1
    if x <= 9 : 
        return 0
    
    # sum = 400
    # len = 101
    
    x -= 9
    t = x//400
    rem = x%400
    t *= 101
    s = 0
    i = 0
    while ( i < 101 and s < rem ) :
        s += DB[i]
        i += 1
    if (e) :
        if ( s > rem ) :
            i -= 1
    return t+i
        

def countofcollisions(a,b) :
    low = searchh(a,False)
    hi = searchh(b,True)
#     print(low,"   :    ",hi)
    return hi-low+1

def main() :
    
    t = int(input()) 
    ansl = []
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
#         print("hello")
        ansl.append(countofcollisions(start_y,end_y)) 
        
    fa = ansl.pop()
    for i in ansl :
        print(i)
    print(fa,end='')
main()