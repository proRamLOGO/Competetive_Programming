#include <iostream>

using namespace std ;

class pnumber {

public:

    short int *arr;

    pnumber( string num ) {
        arr = new short int[10000000] ;
        for ( auto i = 0 ; i < num.size() ; ++i ) 
            arr[i] = (int)(num[num.size()-1-i]) - '0' ;
    }

    bool add( pnumber num ) {
        short int 
    }

}