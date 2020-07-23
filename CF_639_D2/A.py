# import sys
# sys.stdin = open('CF_639_D2/input.txt', 'r') 
# sys.stdout = open('CF_639_D2/output.txt', 'w')

t = int(input()) 

for T in range(t) :
    
    n = input().split()
    m = int(n[0])
    n = int(n[1])
    if ( n == 1 or m == 1 or n*m == 4 ) :
        print("YES")
    else :
        print("NO")

    
