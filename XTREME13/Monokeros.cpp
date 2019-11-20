#include <bits/stdc++.h>
#define lli long long int 

using namespace std ;

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

class BST {

public:

    node *root ;

    BST() {
        root = NULL ;
    }

    void insert( lli data, node* root, long unsigned int level ) {

        if ( data > root->data ) 
            if ( root->right != NULL ) 
                insert( data, root->right, level+1 ) ;
            else {
                root->right = new node(data) ;
                cout << level << ' ' ;
            }
        
        else
            if ( root->left != NULL )
                insert( data, root->left, level+1 ) ;
            else {
                root->left = new node(data) ;
                cout << level << ' ' ;
            }

    } 

    void buildBST( vector<lli> v) {
        
        for ( auto i : v ) {
            if( this->root == NULL ) {
                this->root = new node( i ) ;
                cout << 1 << ' ' ;
            }
            else
                insert( i, this->root, 2 ) ;
        }

    }

    void inOrder( node* root ) {

        if ( root == NULL )
            return ;
        
        inOrder( root->left  ) ;
        cout << root->data << ' ' ;
        inOrder( root->right ) ;

    }

};

int main() {

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

    BST bst ;
    bst.buildBST(v) ;

}
