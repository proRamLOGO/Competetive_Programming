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

        int n, mine = 200 ;
        cin >> n ;
        int arr[n] ;
        vector< vector< int > > pos(n+1,vector<int>(0)) ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> arr[i] ;
            pos[arr[i]].push_back(i) ;
        }

        bool ans = false ;

        for ( int i = 1 ; i <= n ; ++i ) {
            if ( pos[i].size() > 2 ) {
                ans = true ;
                break ;
            } else if ( pos[i].size() > 1 ) {
                if ( pos[i][1] - pos[i][0] > 1 ) {
                    ans = true ;
                    break ;
                }
            }
        }

        if ( ans ) {
            cout << "YES" << endl ;
        } else {
            cout << "NO" << endl ;
        }


    }

}
