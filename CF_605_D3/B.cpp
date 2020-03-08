#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q ;
    cin >> q ;

    while ( q-- ) {

        string path, new_path = "" ;
        cin >> path ;

        int l, r, d, u ;
        l = r = u = d = 0 ;
        
        for ( auto i : path ) 
            switch( i ) {
                case 'U' :
                    ++u ;
                    break ;
                case 'D' :
                    ++d ;
                    break ;
                case 'L' :
                    ++l ;
                    break ;
                case 'R' :
                    ++r ;
                    break ;
            }
        
        int horizontal = min(l,r) ;
        int vertical = min(u,d) ;

        // if ( horizontal == 0 and ( u+d >= 0 and vertical == 0 ) )  cout << 0 ;             
        // if ( vertical == 0 and ( l+r >= 0 and horizontal == 0 ) )  cout << 0 ;

        if ( horizontal == 0 and vertical != 0 )
            new_path = "UD" ;
        else if ( vertical == 0 and horizontal != 0 )
            new_path = "LR" ;
        else
            new_path += string(vertical,'U') + string(horizontal,'L') + string(vertical,'D') + string(horizontal,'R') ;

        cout << new_path.size() << endl  ;
        cout << new_path << endl  ;


    }

}
