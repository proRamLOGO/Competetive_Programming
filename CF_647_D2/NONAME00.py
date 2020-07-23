import sys
sys.stdin = open('CF_647_D2/input.txt', 'r') 
sys.stdout = open('CF_647_D2/output.txt', 'w')
#******************************************************************

class node(object) :
    def __init__(self,val,deg) :
        self.val = val 
        self.deg = deg
    def __str__(self) :
        return("[%i,%i]" %(self.val,self.deg))


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


# for i in graph :
#     print (i," : ",end='')
#     for j in graph[i] :
#         print (j,', ',end='')
#     print()

# GRAPH MADE ********************************
    
bfs = [ pick[i] for i in range(1,n+1) if pick[i].deg==1 ]
if (len(bfs)==0) :
    print(-1)
    exit(0)

lvl = 1
ans = []
while len(bfs) :
    node = bfs.pop(0) 
    lvl = node.deg
    node.deg = -1 #means submitted
    ans.append(node.val)

    for i in graph[node] :
        if i.deg == -1 :
            continue
        elif i.deg > lvl+1 :
            pass
        elif i.deg < lvl+1 :
            print(-1)
            exit(0)
        else :
            bfs.append(i)
    
print(*ans)

    