import sys
sys.stdin = open('CF_653_D3/input.txt', 'r') 
sys.stdout = open('CF_653_D3/output.txt', 'w')


n,K = list(map(int,input().split()))
l = [ list(map(int,input().split())) for _ in range(n) ]
al,bo,bt = [],[],[]
for i in l :
    if ( i[1]==1 and i[2]==1 ) :
        bt.append(i[0])
    elif i[1]==1 and i[2]==0 :
        al.append(i[0])
    elif i[1]==0 and i[2]==1 :
        bo.append(i[0])

al.sort()
bt.sort()
bo.sort() 
i,j,k = 0,0,0
ans,cnt = 0,0
# print(al,bt,bo)

while i<len(al) and j<len(bo) and k<len(bt) and cnt<K :
    if ( al[i]+bo[j] < bt[k] ) :
        ans += al[i]+bo[j]
        i += 1
        j += 1
    else :
        ans += bt[k]
        k += 1
    cnt += 1

while k<len(bt) and cnt<K :
    ans += bt[k]
    k += 1
    cnt += 1

while cnt<K and i<len(al) and j<len(bo) :
    ans += al[i]+bo[j]
    i += 1
    j += 1
    cnt += 1

if ( cnt < K ) :
    print(-1)
else :
    print(ans)
 