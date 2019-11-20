#include <bits/stdc++.h>
#define lli long long int 

using namespace std ;

bool solve( string s, int curr, int B, int x, int l, vector< string >& chain  ) {

    //BaseC
    if ( l==x ) {
        
        chain.push_back(s) ;
        if(0) {
            cout << "New Generates string is " << s ;
            cout << "\nChain is : "  ;
            for ( auto i : chain )
                cout << i ;
            cout << endl ;
        }
        //cout << "c.s*x : " << chain.size()*x << " : " << x << " : " << curr << endl ;
        if ( ((chain.size())*x) >= curr ) {
            //cout << "hey" << endl ;
            //cout << chain[chain.size()-1] << endl ;
            string s = chain[ chain.size()-1 ] ;
            int j = x*(chain.size()-1) ;
            cout << s[curr - j - 1 ] << endl ;
            return false ;
        }
        return true ;
        
    }

    for ( int i = 0 ; i < B ; ++i ) {
        char ch = 'a'+i ;
        bool res = solve(s+ch, curr, B, x, l+1, chain) ;
        if( !res )
            return false ;
    }

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while ( t-- ) {

        int X, B ;
        cin >> B >> X ;
        int x = log(X) / log(B) ;

        int skip = B * (pow(B,x) - 1) / (B-1) ;

        int curr = X-skip ;

        //cout << "hey1" << endl ;
        //cout << B << ' ' << x << ' ' << skip << ' ' << curr << endl ; 

        if ( curr <= x ) {
            cout << 'a' << endl ;
            continue ;
        }
        vector< string > v ;
        solve("",curr,B,x+1,0,v) ;

    }



}
