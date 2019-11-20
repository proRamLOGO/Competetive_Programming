def main() :
    t = int(input())
    for T in range(t) :
        n = input()
        ans = 10**9
        if len(n)==1 :
            print(n)
            continue 
        for i in range(len(n)) :
            s1 = n[:i]
            s2 = n[i+1:]
            #print("s1 = %s and s2 = %s" %(s1,s2))
            ans = min(ans,int(s1+s2))

        print(ans)
            
main()
