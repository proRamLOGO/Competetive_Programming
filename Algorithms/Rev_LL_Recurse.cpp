#include <iostream>
#define nl cout << '\n' 
#define nll cout << "\n\n" 
using namespace std ;

class node {
public:
    int data ;
    node* next ;
    node( int data ) {
        this->data = data ;
        this->next = NULL ;
    }
    //friend ostream &operator<<( ostream &os, node*head );
    //friend istream &operator>>( istream &is, node*&head );
};

node* reverse( node* root) {

    if ( root->next == NULL ) 
        return root;
     
    node* t = reverse( root->next ) ;
    root->next->next = root ;
    return t ;

}

void print( node* head ){
    cout << "\nList is: \n" ;
    node* temp = head;
    while( temp != NULL ) {
        cout << temp->data << ' ' ;
        temp = temp->next ;
    }
    nll ;
}
ostream& operator<<(ostream &os, node*head) {
    print(head) ;
    return os ;
}
node* input( node*&head ){
    int x ;
    cin >> x ;
    node* temp = head;
    while ( x!=-1 ) {
        if( head==NULL ) 
            head = new node(x) ;
        else {
            temp = head;
            while( temp->next != NULL ) 
                temp = temp->next ;
            temp->next = new node(x) ;
        }
        cin >> x ;
    }
    return head ;
}

istream& operator>>(istream &is, node*&head) {
    input(head) ;
    return is ;
}

int main() {


    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;

    node *head = NULL, *temp ;
    
    cin >> head ;
    cout << "took" << head->data <<endl;
    cout << head << endl ;

    temp = head ;
    head = reverse( temp ) ;
    temp->next=NULL ;
    
    cout << "\nReversed List is: \n" ;
    cout << head << endl ;
    nl; 
    
}