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

class MinStack {
public:
    /** initialize your data structure here. */
    vector< int > v, me ;
    
    void push(int x) {
        this->v.push_back(x) ;
        if ( this->v.size()==1 )
            this->me.push_back(x) ;
        else 
            this->me.push_back( min(x,this->me[this->me.size()-1]) ) ;
    }
    
    void pop() {
        if ( this->v.size() > 0 ) {
            this->v.pop_back() ;
            this->me.pop_back() ;
        }
    }
    
    int top() {
        return this->v[this->v.size()-1] ;
    }
    
    int getMin() {
        return this->me[this->me.size()-1] ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
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
        
        int n;
        cin >> n ;
        // Minstack prepare

    }

    return 0 ;

}
