import sys
sys.stdin = open('CF_641_D2/input.txt', 'r') 
sys.stdout = open('CF_641_D2/output.txt', 'w')
linp = "list(map(int,input().split()))"

t = int(input()) 

for T in range(t) :
    n = int(input())
    l = eval(linp)
    print(l)