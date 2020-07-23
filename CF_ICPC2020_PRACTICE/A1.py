file = open('sort.txt','r')
l = list(map(int,file.read().split()))
file.close()
l = l[1:]
l.sort()
file = open('sort.txt','w')
file.write(' '.join([str(i) for i in l] ))
file.close()

