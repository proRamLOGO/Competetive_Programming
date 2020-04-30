#include <bits/stdc++.h>

using namespace std ;

struct node {

	int val ;
	node *next ;
	node( int val ) {
		this->val = val ;
		this->next = nullptr ;
    } 
};

void print( node* head ) {
    node *temp = head ;

    cout << "************************************************************************************************" <<endl ;
    while (temp != nullptr) {
        cout << temp->val << ' ' ;
        temp = temp->next ;
    }
    cout << "\n************************************************************************************************" <<endl ;

}

class FirstUnique {

private:
	node *start, *end; // Linked List for unique and ordered elements
	int firstunq;
	unordered_map< int, node* > loc ;

public:
	FirstUnique( vector<int> &nums ) {
		this->firstunq = -1 ;
		this->start = nullptr ;
		for ( auto i : nums ) 
            this->add(i) ;	
    }

    void add( int val ) {
        // cout << endl << "+=+=+=+=+=+Val = " << val << "=+=+=+=+=+=+=+=+=" << endl ;
        auto itr = this->loc.find(val) ;
        // add the new node to end ;
        if (itr == loc.end()) {
            
            cout << endl <<"In 1" ;
            if ( this->start == nullptr ) {
                // cout << endl <<"    In 1.1" ;
                this->start = new node(val) ;
                this->end = this->start ;
                this->loc[val] = this->start ;
            } else {
                // cout << endl <<"    In 1.2" ;
                // if (val == 791) cout << "here babe" << endl;
                this->end->next = new node(val) ; //DEBUGITT
                // if (val == 791) cout << endl << "node made"<< endl ;
                
                this->end = this->end->next ;
                // if (val == 791) cout << "end updt" << endl ;

                this->loc[val] = this->end ;
                // if (val == 791) cout << "here" << endl;
            }
        } 
        // means we have had it before and if it is present in LL then delete it
        else if ( itr->second != nullptr ) {
            // cout << endl <<"In 2" ;
            node *temp = itr->second->next ;
            
            if ( itr->second == this->start ) {
                // cout << endl << "   In 2.1" ;
                this->start = this->start->next ;
                if ( this->start == nullptr )
                    this->end = nullptr ;
            }
            else if ( temp != nullptr ) {
                // cout << endl << "   In 2.2" ;
                itr->second->val = temp->val ;
                itr->second->next = temp->next ;
                loc[itr->second->val] = itr->second ;
                delete temp ;
            } else {
                // cout << endl << "   In 2.3" ;
                temp = this->start ;
                while ( temp->next->next != nullptr ) temp = temp->next ;
                delete temp->next ;
                temp->next = nullptr ;
            }
            
            this->loc[val] = nullptr ;
        }
        
        // cout << "**************Bye bye success for " << val << endl <<endl ;
        // print(this->start) ;

    }
        
    int showFirstUnique() {

        if (this->start == nullptr) {
           return -1 ;
        } else {
            return this->start->val;
        }
    }

};

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    vector v = {70,80,434,460,432,473,165,251,941,21,867,311,973,739,723,309,254,738,450,531,258,72,174,331,761,211,413,302,752,552,28,693,879,878,703,907,676,653,584,430,21,486,738,975,564,945,529,643,83,103,183,915,180,381,505,322,317,435,583,472,714,114,761,623,340,916,2,570,419,826,965,461,85,460,260,80,659,900,993,72,732,643,85,261,295,609,569,835,684,496,729,220,724,721,566,885,584,256,581,828,184,194,990,861,966,309,552,766,601,706,162,108,143,755,809,84,913,306,802,532,223,434,869,266,37,283,966,179,506,284,591,541,902,823,309,897,143,661,256,143,839,924,352,606,732,638,348,331,265,265,601,731,791,72} ;
    FirstUnique fq( v ) ;

    int q ;
    cin >> q ;
    while ( q!= -1 ) {
        int val ;
        if ( q == 1 ) {
            cin >> val ;
            fq.add(val) ;
        } else {
            cout << fq.showFirstUnique() ;
        }
        cin >> q ;
    }



}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */