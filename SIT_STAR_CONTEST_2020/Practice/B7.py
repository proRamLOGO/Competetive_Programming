class node(object) :
    def __init__(self,val,deg) :
        self.val = val 
        self.deg = deg
    def __str__(self) :
        return("[%i,%i]" %(self.val,self.deg))

for _ in range(int(input())) :
    n,m = list(map(int,input().split()))
    pick,graph = {},{}
    gq = [ list(map(int,input().split())) for i in range(m) ]
    desdeg = [0]+list(map(int,input().split()))
    for i in range(n+1) :
        x = node(i,desdeg[i])
        pick[i] = x
        graph[x] = []
    for i in gq :
        graph[pick[i[0]]].append(pick[i[1]])
        graph[pick[i[1]]].append(pick[i[0]])
    graph[pick[2]][1].val = 100
    for i in graph :
        print (i," : ",end='')
        for j in graph[i] :
            print (j,', ',end='')
        print()
