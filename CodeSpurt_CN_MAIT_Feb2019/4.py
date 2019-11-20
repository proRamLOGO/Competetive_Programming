def main() :
    
    n = int(input())
    names = list()
    track = list()
    
    for i in range(n) :
        names += [ raw_input() ]

    for i in range(n) :
        sub = ""
        for j in range( len(names[i]) ) :
            
            found = 0
            sub += names[i][j]
            #print "sub = ", sub

            for k in range(i) :
                #print " chking with ", names[k][:j+1]
                if sub == names[k][:j+1] :
                    #print " yes same"
                    found = 1
                    break 

            if not found and sub not in track :
                #print " found nowhere hence adding in list track"
                track += [ sub ]
                #print track
                break
            
            #print

    for i in track :
        print i

main()