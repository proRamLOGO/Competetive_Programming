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

    int t ;
    cin >> t ;

    while ( t-- ) {

        string path ;
        cin >> path ;

        path += "R" ;

        bool cntingL = false ;
        long int maxCL = 0, currL = 0 ;

        for ( long int i = 0 ; i < path.size() ; ++i ) {

            if ( path[i] == 'L' ) {
                if ( !cntingL ) {
                    cntingL = true ;
                }
                ++currL ;
            }
            else if ( path[i] == 'R' ) {
                if ( cntingL ) {
                    // cout << currL << " " ;
                    cntingL = false ;
                    maxCL = max(maxCL,currL) ;
                    currL = 0 ;
                }
            }

        }

        // cout << endl << endl ;;

        cout << maxCL+1 << endl ;


    }

}
