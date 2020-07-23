

#include <iostream>
#define int long int
using namespace std;

auto isleap = []( int y ) {
    return ( (y % 4 == 0 and y % 100 != 0) or y % 400 == 0 ) ;
};

int32_t main() {
    
    int n;
    cin >> n ;

    int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31} ;

    while ( n ) {
        
        int d1,m1,y1,c1, d2,m2,y2,c2, ansd = 0, ansc = 0 ;
        cin >> d1 >> m1 >> y1 >> c1 ;
        for ( int i = 1 ; i < n ; ++i ) {
            months[2] = 28;
            cin >> d2 >> m2 >> y2 >> c2 ;

            int nd, nm, ny ;

            if ( isleap(y1) ) {
                ++months[2] ;
            }

            nd = d1+1 ;
            nm = m1 ;
            ny = y1;
            if ( nd > months[m1] ) {
                nd = 1;
                nm = m1+1 ;
                if (nm==13) {
                    nm = 1 ;   
                    ny = y1+1 ;
                }
            }
            
            // cout << d1 << ' ' << m1 << ' ' << y1 << ' ' << c1 << '\n' ;
            // cout << d2 << ' ' << m2 << ' ' << y2 << ' ' << c2 << '\n' ;
            // cout << nd << ' ' << nm << ' ' << ny << ' ' << c2-c1 << '\n' ;
            // cout << endl ;

            if ( nd==d2 and nm==m2 and ny==y2 ) {
                ansd += c2-c1 ;
                ++ansc ;
            }

            d1 = d2 ;
            y1 = y2 ;
            m1 = m2 ;
            c1 = c2 ;

        }

        cout << ansc << ' ' << ansd << endl ;
        // cout << "****************************************\n\n" ;
        cin >> n ;

    }


}
