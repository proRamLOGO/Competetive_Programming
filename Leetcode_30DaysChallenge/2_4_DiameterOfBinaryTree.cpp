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


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void initTreeNode( TreeNode t, int x) { 
    t.val = x ; 
    t.left = NULL ;
    t.right = NULL ;
}

class Solution {
public:
    
    int height(TreeNode* root, int &ans) {
        
        if ( root == NULL )
            return 0 ;
        
        int lh = height(root->left,ans) ;
        int rh = height(root->right,ans) ;
        
        int h = lh+rh ;
        // if(h==1)h=0;
        ans = max(ans,h) ;
        
        return 1+max(lh,rh) ;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (root==NULL)
            return 0 ;
        
        int ans = INT_MIN ;
        height(root,ans) ;
        
        return ans ;
        
    }
};

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
