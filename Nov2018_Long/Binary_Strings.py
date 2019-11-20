n = [ long int(i) for i in input().split() ]
q = n[-1] 
n = n[0]

l = list() 
for i in range(n) :
    l += [long int(input(),2)]

quer = list()
for i in range(q) :
    quer = input().split()
    lt = long int(quer[0])
    rt = long int(quer[1])
    b = long int(quer[2],2)
    ans = lt-1
    m = 0
    for y in range(lt-1,rt) :
        if m < b^l[y] :
            m = b^l[y] 
            ans = y
    prlong int (ans+1) 