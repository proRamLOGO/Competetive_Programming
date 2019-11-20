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

        int n , k ;
        cin >> n >> k ;
        priority_queue < int, vector < int >, greater < int > >  q ;
        vector< int > v ;
        int s = 0 ;
        for ( auto i = 0 ; i < n ; ++i ) {
            int ele ;
            cin >> ele ;
            if ( ele > k ) {
                ++s ;
                q.push(ele) ;
            }
            else 
                v.push_back(ele) ;
        }

        if ( s == 1 ) {
            int sum = q.top() ;
            for ( auto i : v )
                sum += i ;
            cout << sum << endl ;
            continue ;
        }

        while ( !q.empty() and q.top() > k ) {
            int x = q.top() ;
            q.pop() ;
            int y = q.top() ;
            q.pop() ;
            --x ;
            --y ;
            q.push(x) ;
            q.push(y) ;
        }
        int sum = 0 ;
        while ( !q.empty() ) {
            sum += q.top() ;
            //cout << q.top() << endl ;
            q.pop() ;
        }
        for ( auto i : v ) 
            sum += i ;
        cout << sum << endl ;
        

    }

    return 0 ;

}
