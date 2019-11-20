#include<iostream>
#include <vector>
using namespace std ;

int main() {

    int n, m, m1=0, m2=0 ;
    cin >> n ;
    int arr[n] ;
    for ( auto i = 0 ; i < n ; ++i ) {
        cin >> arr[i] ;
        if ( m1 < arr[i] ) m1 = arr[i] ;
    }
    cin >> m ;
    int arrr[m] ;
    for ( auto i = 0 ; i < m ; ++i ) {
        cin >> arrr[i] ;
        if ( m2 < arrr[i] ) m2 = arrr[i] ;
    }

    cout << m1 << ' ' << m2 << '\n';

}