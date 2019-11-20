#include <iostream>
#include <set>

using namespace std;

int main() {

    int t;
    cin >> t;
    while ( t-- ) {

        long long int n, m, k, l, a ;
        cin >> n ;
        set< int > s ;
        cin >> m >> k >> l ;
 
        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> a;
            s.insert(a);
        }
 
        set<int> :: iterator itr = s.begin();
 
        long long int _time = ( m + 1 ) * l;
        long long int min_time = _time ;
 
        int prev_itr = 0;
        int i = 0;
        for ( itr = s.begin() ; itr != s.end() ; ++itr ) {
           _time -= ( *itr - prev_itr ) ;
            prev_itr = *itr ;
            if ( min_time >_time ) min_time = _time;
           _time += l ;
        }
       _time -= k - prev_itr;
        if( min_time > _time ) min_time =_time;

        cout << min_time << endl;
 
    }
 
}