
import sys
sys.stdin = open('input.txt', 'r') 
sys.stdout = open('output.txt', 'w')

n,m,q = map(int, input().split() ) ;
s = input()
t = input()

cnt = [0]*(n+1)

for i in range(n) :
    ss = s[i:]
    cnt[i] = ss.count(t)

# print(cnt)

for i in range(q) :
    l,r = map(int, input().split())
    if (l==r and m!= 1) :
        print(0)
        continue
    if (r-l+1 < m ) :
        print(0)
        continue 
    if (m==1) :
        print(cnt[l-1]-cnt[r])
    else:
        print(cnt[l-1]-cnt[r-1])
