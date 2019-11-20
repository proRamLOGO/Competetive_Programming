#include <iostream>
#include <vector>

using namespace std ;

void merge( vector<int>& v, int l, int r, int m ) {

    int i = l, j = m+1 ;
    vector<int> arr ;
    for ( i,j ; i <= m && j <= r ; ) {

        if ( v[i] <= v[j] ) {
            arr.push_back(v[i]) ;
            ++i ;
        }
        else {
            arr.push_back(v[j]) ;
            ++j ;
        }

    }

    while ( j <= r ) {
            arr.push_back(v[j]) ;
            ++j ;
    }
    while ( i <= m ) {
            arr.push_back(v[i]) ;
            ++i ;
    }

    for ( i = l ; i < r+1 ; ++i ) 
        v[i] = arr[i-l] ;

}

void mergeSort( vector<int>& v, int l, int r ) {

    if( l < r ) {

        int m = (l+r)/2 ;
        mergeSort( v, l, m ) ;
        mergeSort( v, m+1, r ) ;

        merge(v, l, r, m ) ;

    }

}

int main() {

    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    
    int n ;
    cin >> n ;
    vector< int > v(n) ;
    for ( auto i = 0 ; i < n ; ++i ) 
        cin >> v[i] ;

    mergeSort(v, 0, v.size()-1 ) ;

    for ( auto i = 0 ; i < n ; ++i ) 
        cout << v[i] << ' ' ;

    return 0;
}
