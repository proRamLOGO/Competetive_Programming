#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

class node {
public:
    int key, val ;
    node *next, *prev ; 
    node( int key, int val ) {
        this->key = key ;
        this->val = val ;
        this->next = this->prev = nullptr ;
    }
};

class LRUCache {
public:
    node *root ;
    unordered_map< int, node* > addr ;
    
    LRUCache(int capacity) {
        
        this->root = new node(-1,-1) ;
        node *temp = this->root ;
        for ( int i = 1 ; i < capacity ; ++i ) {
            temp->next = new node(-1,-1) ;
            temp->next->prev = temp ;
            temp = temp->next ;
        }
        temp->next = this->root ;
        this->root->prev = temp ;
        
        // CLL of size capacity initialized.
        
    }
    
    int get(int key) {
        auto found = addr.find(key) ;
        
        if ( found == addr.end() )
            return -1 ;
        
        if ( found->second != this->root ) {
            //remove and fix 
            found->second->prev->next = found->second->next ;
            found->second->next->prev = found->second->prev ;

            //add and fix before root
            this->root->prev->next = found->second ;
            found->second->prev = this->root->prev ;
            this->root->prev = found->second ;
            found->second->next = this->root ;
        
        } else {
            this->root = this->root->next ;
        }
        
        return found->second->val ;
    }
    
    void put(int key, int value) {
        
        if ( addr.find(key) == addr.end() ){
            if ( this->root->key != -1 and this->root->val != -1 ) {
                addr.erase(this->root->key) ;
            }
            this->root->key = key ;
            this->root->val = value ;
            addr[key] = this->root ;
            this->root = this->root->next ;
        }
        get(key) ;
        addr[key]->val = value ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t=1 ;
    // cin >> t ;

    while( t-- ) {
        
        int c, q ;
        cin >> c >> q ;
        LRUCache lru(c);

        while (q--) {
            int qt, n1, n2 ;
            cin >> qt >> n1 ;
            
            // get
            if ( qt==1 ) {
                cout << lru.get(n1) ;
            } 

            //put
            else {
                cin >> n2 ;
                lru.put(n1,n2) ;
            }
        }

    }

    return 0 ;

}
