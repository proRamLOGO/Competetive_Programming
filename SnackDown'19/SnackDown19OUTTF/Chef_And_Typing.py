def main() :
    t = int(input())
    left = 'df'
    right = 'jk'
    while t :
        t = t - 1
        total = 0
        words = {}
        n = int(input())
        for i in range(n) :
            time = 0
            word = input()
            if word not in words :
                time = 0.2
                words[word] = 0
                for y in range(1,len(word)) :
                    if word[y-1] in left and word[y] in right :
                        time += 0.2
                    elif word[y-1] in right and word[y] in left :
                        time += 0.2
                    else :
                        time += 0.4
                words[word] = time 
            else :
                time = words[word]/2
            total += time
        print(int(total*10))
main()