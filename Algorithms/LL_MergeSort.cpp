#include <iostream>
using namespace std ;

class node {

public:
    int data ;
    node* next ;
    node( int d ) {
        data = d ;
        next = NULL ;
    }

};

void print( node* head ) {
    node* t = head ;
    while( t != NULL ) {
        cout << t->data << ' ' ;
        t = t->next ;
    }
    cout << endl << endl ;
}

void buildList( node*&head ) {
    int x ;
    cin >> x ;
    while( x!=-1 ) {
        if ( head == NULL ) 
            head = new node(x) ;
        else {
            node *t = head ;
            while( t->next != NULL ) 
                t = t->next ;
            t->next = new node(x) ;
        }
        cin >> x ;
    }
    
}

node* mid( node*head ) {

    node *fp = head, *p = head ;
    while(fp->next->next->next != NULL ) {
        p=p->next ;
        fp = fp->next->next ;
    }
    return p ;

}

node* merge( node *&h1, node *&h2 ) {
    
    node *p1 = h1, *p2 = h2;
    while( p1 != NULL || p2 != NULL ) {

        if ( p1->data < p2->data ) 
            p1 = p1->next ;
        else {
            node *t = p1->next ;
            node *t2 = new node (p2->data) ;
            p1->next = t2 ;
            t2->next = t ;
            p1 = p1->next->next ;
        }

    }
    print(h1) ;
    return h1 ;

}

node* mergesort( node**head ) {

    if ( (*head)->next == NULL )
        return *head ;

    node *m = mid(*head) ;
    cout << "For " << (*head)->data << " mid is "<<  m->data << endl << endl;
    
    node *h1 = *head ;
    node *h2 = m->next ;
    m->next = NULL ;
    // cout << "Linked List with head " << head->data << endl ;
    //cout << h1->data ;
    print(h1) ;
    //cout << "Linked List with head " << h2->data << endl << endl;
    //print(h2) ; 
    //node *he1 = mergesort(h1) ;
    //node *he2 = mergesort(h2) ;
    //return NULL;

}

int main() {

    //#if ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    

    node *head = NULL ;
    buildList(head) ;
    print(head) ;
    //mergesort(&head) ;
    //print(head) ;


}