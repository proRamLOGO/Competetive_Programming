#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n ;
    int x = n ;

    int counter = 0 ;

    if ( x ) {
        for (  ; x/10 != 0 ; x/=10 ) {

            int i = x%10 ;
            if( i == 0 ) continue ;
            if ( n%i == 0 ) ++counter ;

        }

        if ( n%x == 0 ) ++counter ;

        cout << counter << endl ;
    }

}