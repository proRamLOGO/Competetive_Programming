for t in range(int(input())):
	n = int(input())
	l = list(map(int,input().split()))
	ps = [0]
	s = 0
	for i in l :
	    s += i
	    ps.append(s)
	ans = 0
	for i in range(n) :
	    for j in range(i,n) :
	        sm = ps[j+1] - ps[i]
	        sqrt = sm**0.5
	        if ( sqrt == int(sqrt) ) :
	            ans += 1
	print("Case #",t+1,": ",ans,sep='')
