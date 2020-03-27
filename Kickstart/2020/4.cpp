#include <bits/stdc++.h>
#define llui long long unsigned int
using namespace std ;

const int ALPHABET_SIZE = 26; 

struct TrieNode { 
	struct TrieNode *children[ALPHABET_SIZE]; 
	bool isEndOfWord; 
}; 

struct TrieNode *getNode(void) { 
	struct TrieNode *pNode = new TrieNode; 
	pNode->isEndOfWord = false; 
	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 
	return pNode; 
} 

void insert(struct TrieNode *root, string key) { 
	struct TrieNode *pCrawl = root; 
	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 
	pCrawl->isEndOfWord = true; 
} 

bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t ;
    cin >> t ;
    
    for ( int T = 1 ; T <= t ; ++T ) {
        
        int n, k;
        cin >> n >> k ;
        vector<string> v(n) ;
        struct TrieNode *root = getNode(); 
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            insert(root, v[i]); 
        }

        
         
        int ans=0;
        cout << "Case #" << T << ": " << ans << endl ;
        
    }
    
}