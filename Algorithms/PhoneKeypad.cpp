#include<iostream>
using namespace std ;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printSubS( char *s, char *op, int i, int j ) {

    if ( s[i]=='\0' ) { 
        op[j] = '\0' ;
        cout << op << endl ;
        return ;
    }
    int digit = s[i]-'0' ;
    for( auto k = 0 ; keypad[digit][k] != '\0' ; ++k ) {
        op[j++] =  keypad[digit][k] ;
        printSubS(s,op,i+1,j+1) ;
    }

}

int main() {

    int t;
    cin >> t ;
    while(t--) {
        char s[100],op[100] ;
        cin >> s ;
        printSubS(s,op,0,0) ;
    }

}