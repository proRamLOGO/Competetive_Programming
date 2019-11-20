#include <iostream>
#include <vector> 

using namespace std;

int main() {

    int n;
    cin >> n ;
    ( n%4 == 0 ) ? cout << n+1 : cout << n-1 ;

}