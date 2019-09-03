#include <iostream>
//This program finds an element in an array using binary search

using namespace std;

int bin_search( int arr[] , int size , int element ) {

    int mid , hi = size-1 , lo = 0;
    while( hi >= lo ) {

        mid = ( hi + lo ) / 2 ;
        if ( arr[mid] == element ) return mid ;
        else if ( arr[mid] < element ) lo = mid + 1 ;
        else hi = mid - 1;

    }
    return -1 ;

}

int main() {

    int n ;
    cin >> n;
    int  arr[n] ;

    for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;

    int x;
    cin >> x;

    int index = bin_search( arr , n , x ) ;
    cout << endl << index << endl;

}
