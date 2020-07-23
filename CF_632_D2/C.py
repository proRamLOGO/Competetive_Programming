def func(lst):
    prefix = [0]
    for x in lst:
        prefix.append(prefix[-1] + x)
    freq = {}
    for y in prefix:
        if y in freq:
            freq[y] += 1
        else:
            freq[y] = 1
##    ans = 0
##    for i in freq.values() :
##        
    return sum(v*(v-1) // 2 for v in freq.values())

def main() :
    n = int(input())
    l = map(int, input().split())        
    print(n-func(l))

main()
