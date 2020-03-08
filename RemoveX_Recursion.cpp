#include<bits/stdc++.h>

using namespace std;  

string removeX( string input ) {  
    
    if( input.length() == 0 ) {
        return "" ;
    }

    string ret = removeX(input.substr(1));  
    if ( input[0] == 'x')
        return ret ;
    else {
        string x = input.substr(0,1) ;
        return x+ret ;
    }
}

int main() {

    string s ;
    cin >> s ;
    cout << removeX(s) << endl ;

}
