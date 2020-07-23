import sys
sys.stdin = open('CF_E87_D2/input.txt', 'r') 
sys.stdout = open('CF_E87_D2/output.txt', 'w')
linp = "list(map(int,input().split()))"

from math import sin,cos,tan

def diagonal(n) :
	if ( n < 0): 
		return -1
	return 1/sin(18/n)

for _ in range(int(input())) :
    n = int(input())
    n*=2
    intang = ((n-2)*180)//n
    a = intang//2
    b = 90
    c = 180-a-b
    dg = 1/sin(c)
    base = 1/tan(c);
    print(base)