import sys
sys.stdin = open('CF_658_D2/input.txt', 'r') 
sys.stdout = open('CF_658_D2/output.txt', 'w')
linp = "list(map(int,input().split()))"

for T in range(int(input())) :
    # n = int(input())
    l = list(map(int,input().split()))
    print(l)
