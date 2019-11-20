#include <iostream>
#include <math.h>
#include <vector>

using namespace std; 

long int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    long int n, q, k ;
    cin >> n >> q >> k ;
    vector< long int > arr(n), b(2)  ;
    vector< vector< long int > > pos ;
    bool flag = 0 ;

    for ( auto i = 0 ; i < n ; ++i ) {

        cin >> arr[i] ;
        if ( !flag && arr[i] == 1 ) {
            b[0] = i ;
            flag = 1 ;
        }
        if ( flag && arr[i] == 0 ) {
            b[1] = i-1 ;
            flag = 0 ;
            pos.push_back(b) ;
        } 

    }
    if ( flag ) {
        b[1] = n-1 ;
        flag = 0 ;
        pos.push_back(b) ;
    } 

    cout << "\nPostions of group of 1s for given array\n" ;
    for ( auto c : pos ) cout << "( " << c[0] << " , " << c[1] << " ), " ;
    cout << endl ;

    string s;
    cin >> s ;

    long int shift = 0; 

    for ( auto i = 0 ; i < q ; ++i ) {

        if ( s[i] == '?' ) {

            long int max = 0 ;
            for ( auto c : pos ) {
                if ( ( c[1] - c[0] + 1 ) > max  ) {
                    max = (c[1] - c[0] + 1 ) ;
                    if ( ( c[1] - c[0] + 1 ) > k ) {
                        max = k ;
                    }
                }
            }
            cout << max << endl ;

        }

        if ( s[i] == '!' ) {
            // last elemnt after shift rotations is given by arr[ (n-1 - shift)%n ] ;
            if ( arr[ n-1 ] == 1 ) {
                
                bool flag1 = 0 ;
                for ( auto y = 0 ; y < pos.size() ; ++y ) {
                    
                    pos[y][0]++ ;
                    pos[y][1]++ ;
                    if ( pos[y][0] == 1 ) {
                        pos[y][0] = 0 ;
                        flag1 = 1 ;
                    }
                    if ( pos[y][1] > n-1) pos[y][1]-- ;
                    long int x = y+1 ;
                    if ( pos[y][0] > pos[y][1] ) pos.erase(pos.begin()+x) ;

                }
                if ( !flag1 ) {
                    b[0] = 0 ; 
                    b[1] = 0 ;
                    pos.push_back( b ) ;
                }
                shift++ ;

            }
            else { 

                for ( auto y = 0 ; y < pos.size() ; ++y ) {
                    long int x = y + 1 ;
                    pos[y][0]++ ;
                    pos[y][1]++ ;
                    if ( n <= pos[y][1] ) {
                        pos[y][1]-- ;
                        if ( pos[y][0] > pos[y][1]  ) pos.erase(pos.begin()+x) ;
                    }
                    else if ( n <= pos[y][0] ) pos.erase(pos.begin()+x) ;

                }

                shift++ ;

            }

        
            long int end = arr[n-1] ;
            for ( auto y = n-1 ; y > 0 ; --y ) {
                arr[y] = arr[y-1] ;
            }
            arr[0] = end ;

            cout << "\nUpdates Postions of group of 1s after " << shift << " shifts.\n" ;
            for ( auto c : pos ) cout << "( " << c[0] << " , " << c[1] << " ), " ;
            cout << endl ;

        }

    }

}