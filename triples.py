import sys
sys.stdin = open('input.txt', 'r') 
sys.stdout = open('output.txt', 'w')

DB = [ 1,2,3,4,8,12,5,10,15]
triples = [(1,2,3),(4,8,12),(5,10,15)]
last = 6
while (len(triples) <= 33 ) :
	while last in DB :
		last += 1
	tp = [last]
	f = True
	for i in range(last+1,10000) :
		if i in DB :
			continue
		for j in range(i+1,10000) :
			if j in DB :
				continue
			if (last^i^j == 0) :
				tp.append(i) ;
				tp.append(j) ;
				DB += [last,i,j]
				f = False
				break
		if (not f) :
			break

	triples.append(tuple(tp))

	
for i in triples :
	print (i)