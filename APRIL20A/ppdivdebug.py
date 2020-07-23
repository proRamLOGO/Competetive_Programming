for i in range(2,60) :
    print (i,"  :  ", end='') 
    j = 1
    while j**i <= 10000 :
        print(j**i, end=' , ')
        j += 1
    print()
