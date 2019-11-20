#include <bits/stdc++.h> 
#define lli long long int 
using namespace std; 

class node {

public:

    lli data ;
    node *left ;
    node *right ;

    node( lli data ) {
        this->data = data ;
        this->left = NULL ;
        this->right = NULL ;
    }

};

node* buildBST(vector< lli > arr, int* postIndex, int key, int min, int max, int size) { 
    
    if (*postIndex < 0) 
        return NULL; 
  
    node* root = NULL; 
  
    if (key > min and key < max) { 
        
        root = new node(key); 
        *postIndex = *postIndex - 1; 
  
        if (*postIndex >= 0) { 
            root->right = buildBST(arr, postIndex, arr[*postIndex], key, max, size ); 
            root->right = buildBST(arr, postIndex, arr[*postIndex], min, key, size ); 
        } 
    } 
    return root; 
} 


void inorder( node* node ) 
{ 
    if (node == NULL) 
        return; 
    inorder(node->left) ; 
    cout << node->data << " "; 
    inorder(node->right) ; 
} 
void preorder( node* node ) 
{ 
    if (node == NULL) 
        return; 
    cout << node->data << " "; 
    preorder(node->left) ; 
    preorder(node->right) ; 
} 
void postorder( node* node ) 
{ 
    if (node == NULL) 
        return; 
    postorder(node->left) ; 
    postorder(node->right) ;
    cout << node->data << " ";  
} 
  
int levelOrder( node* head ) {

        queue< node* > levels ;
        levels.push(head) ;
        int no = 1 ;
        while( levels.empty() != true ) {
            if ( levels.front()->left != NULL ){
                levels.push(levels.front()->left) ;
                ++no ;
            }
            if ( levels.front()->right != NULL ){
                levels.push(levels.front()->right) ;
                ++no ;
            }
            cout << levels.front()->data << ' ' ;
            levels.pop() ;
        } 
        return no ;
    } 
int main () 
{ 
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n ;

    vector< lli > v(n) ;
    for ( auto i = 0 ; i < n ; ++i )
        cin >> v[i] ;

    sort(v.begin(),v.end()) ;

    int p = n-1; 
    
    node *BST = buildBST(v, &p, v[p], INT_MIN, INT_MAX, n); 
  
    cout << endl ;
    inorder(BST); 
    cout << endl ;
    preorder(BST); 
    cout << endl ;
    postorder(BST); 
    cout << endl ;
    levelOrder(BST); 
  
    return 0; 
} 