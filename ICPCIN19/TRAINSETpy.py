def isvalid( s ) :
    
    if ( len(s) == 1 ) :
        s += '1' 
        return True ;
    for i in range(1,len(s)) :
        x = s[:i]
        y = s[i:]
        if ( isvalid(x) and isvalid(y) and x <= y ) :
            return True
    return False


n = int(input())
a = ""

for N in range(n) :
    s = input()
    if ( len(s) == 1 ) :
        a += '1' 
        continue ;
    if (isvalid(s)) :
        a += '1'
    else :
        a += '0'
        
print(a)    
