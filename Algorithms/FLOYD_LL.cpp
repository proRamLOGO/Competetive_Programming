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

node* detect( node *head ) {

    node *p = head, *fp = head ; 
    while( p->next != NULL && fp->next != NULL ) {
        p = p->next ;
        fp = fp->next->next ;
        if( p==fp )
            return fp ;
    }
    return NULL ;

}

bool remove( node*&head ) {

    node* back = detect(head) ;
    
    if( back == NULL ) {
        return false ;
    }

    node* temp = head ;
    node* prev = NULL ;
    cout << "LOOP Found at node with data " << back->data << endl ;
    while( temp != back ) {
        prev = back ;
        temp = temp->next ;
        back = back->next ;
    }
    prev->next = NULL ;
    return true ;

}

void print( node* head ) {
    node* t = head ;
    while( t != NULL ) {
        cout << t->data << ' ' ;
        t = t->next ;
    }
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

void makeloop( node*&head, int k ) {

    node *t=head, *b ;
    //k-- ;
    while(k--)
        t=t->next ;
    b=t ;
    cout << b->data ;
    while(t->next != NULL )
        t = t->next ;
    t->next = b ;

}


int main() {

    #if ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    node *head ;
    head = NULL ;
    buildList(head) ;
    print(head) ;
    int n ;
    cin >> n ;
    makeloop(head,n) ;
    if( remove(head) ) 
        cout << "LOOP removed !\n" ;
    else
        cout << "LOOP not found !\n" ;
    //cout << "Hello" ;

}