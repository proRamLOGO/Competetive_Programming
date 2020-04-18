primes = []

def __init__primes() :
    global primes
    primes = [2] 
    isprime = [True for i in range(102) ] 
    for i in range(3,102,2) :
        if isprime[i] :
            primes.append(i) 
            for j in range(i*i, 102, i) :
                isprime[j] = False 
    

def groupAnagrams( strs ) :
    global primes
    table = {}
    
    for i in strs :
        pro = 1
        for j in i :
            pro *= primes[ord(j)-97]
        if pro not in table.keys() :
            table[pro] = []
        table[pro].append(i)
    
    ans = []
    
    for i in table.values() :
        ans.append(i)
    
    return ans

def main() :
    l = input().split() 
    l = groupAnagrams(l)