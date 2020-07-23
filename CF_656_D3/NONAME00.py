import sys
sys.stdin = open('CF_656_D3/input.txt', 'r') 
sys.stdout = open('CF_656_D3/output.txt', 'w')
linp = "list(map(int,input().split()))"

t = int(input()) 

for T in range(t) :
    l = sorted(list(map(int,input().split())))
    o = set(l)
    if ( len(o)==2 ) :
        if (l[-1]==l[-2]) :
            print("YES")
            print(l[0],l[0],l[1])
        else :
            print("NO")
    elif ( len(o)==1 ) :
        print("YES")
        print(l[0],l[0],l[0])
    else :
        print("NO")