#include <iostream>
#include <vector>

using namespace std ;

void heapify( vector<int>& v, int i, int n ) {

    int largest = i ;
    int l = 2*i + 1 ;
    int r = 2*i + 2 ;

    if ( l < n && v[l] > v[largest] ) 
        largest = l ;
        
    if ( r < n && v[r] > v[largest] ) 
        largest = r ;
        
    if ( largest != i ) {
        swap( v[i], v[largest] ) ;
        heapify( v, largest, n ) ;
    }


}

void heapSort( vector< int >& v ) {

    int n = v.size() ;

    for ( auto i = n/2 - 1 ; i >= 0 ; --i ) 
        heapify( v, i, n ) ;

    for ( auto i = n-1 ; i >= 0 ; --i ) {
        swap( v[0], v[i] ) ;
        heapify( v, 0 , i ) ;
    }

}

int main(){

    int n ;
    cin >> n ;
    vector < int > v(n) ;

    for ( auto i = 0 ; i < n ; ++i ) 
        cin >> v[i] ;

    heapSort( v ) ;

    cout << endl ;
    for ( auto c : v ) 
        cout << c << ' ' ;

    cout << endl ;
}