#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    int t;
    cin >> t ;
    while ( t-- ) {

        int n,m;
        bool flag = 0 ;
        cin >> n >> m ;
        long long int ele ;
        int x=0 ,y=0;
        vector< long long int > a, b;
        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> ele ;
            if ( ele ) a.push_back(ele) ; 
        }
        for ( auto i = 0 ; i < m ; ++i ) {
            cin >> ele ;
            if ( ele ) b.push_back(ele) ; 
        }

        sort(a.begin(),a.end()) ;
        sort(b.begin(),b.end()) ;

        if ( a.size() == b.size() ) {
            if ( a == b ) {
                cout << "Bob\n" ;
            }
            else {
                cout << "Alice\n" ;
            }
        }
        else {
            cout << "Alice\n" ;
        }
    }

}