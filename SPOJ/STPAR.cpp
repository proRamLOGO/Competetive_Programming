/*--------------------------------------------
https://www.spoj.com/problems/STPAR/
--------------------------------------------*/

#include <bits/stdc++.h>

using namespace std ;

int main() {

   

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, need=1;
	cin >> n ;
	vector<int> v(n), q ;
	stack<int> s;

    bool ans=true ;
	for ( int i=0 ; i<n ; ++i ) {
        cin >> v[i] ;
    }
    stack<int> lane; 
    bool state = true;
    for (int i = 0; i < v.size(); i++) {
        while (!lane.empty() && lane.top() == need) {
            need++;
            lane.pop();
        }
        if (v[i] == need) {
            need++;
        } else if (!lane.empty() && lane.top() < v[i]) {
            state = false;
            break;
        } else {
            lane.push(v[i]);
        }
    }
    if (state) cout << "yes" << "\n";
    else cout << "no" << "\n";
    //     if ( i>0 ) {
    //         while( !s.empty() and s.top()==need ) {
    //             // q.push_back(s.top()) ;
    //             s.pop() ;
    //             ++need ;
    //         }
    //         if ( v[i-1]==need ) {
    //             // q.push_back(v[i-1]) ;
    //             ++need ;
    //         } else if ( v[i-1]>need && ( s.empty() || ( !s.empty() && v[i-1] <= s.top() ) ) ) {
    //             s.push(v[i-1]) ;
    //         } else {
    //             ans = false ;
    //             break ;
    //         }
                
    //     }
	// }
	
	// // q.push_back(v[n-1]) ;
	
	// // while(!s.empty()) {
	// // 	q.push_back(s.top()) ;
	// // 	s.pop() ;
	// // }
	
	// int x; cin >> x;
	
	// if (ans){
	// 	cout << "yes" ;
	// } else {
	// 	cout << "no" ;
	// }
	// cout << endl ;
	
	
	return 0;
}
