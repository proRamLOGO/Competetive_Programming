#include <iostream>
#include <vector>
#include <queue>
using namespace std ;

int solve(vector<int> &A) {
    
    priority_queue< int, vector<int> , greater<int> > q ;
    for ( int i = 0 ; i < A.size() ; ++i )
        q.push(A[i]) ;
    
    int cost = 0 ;
    while ( 1!=q.size() ) {
        int r1 = q.top() ;
        q.pop() ;
        int r2 = q.top() ;
        q.pop() ;
        // cout << r1 + r2 << endl ;
        q.push(r1+r2) ;
        cost += r1 + r2 ;
    }
    return cost ;
}

int main() {
    int arr[] = {6, 19, 9, 14, 17, 16, 7, 2, 14, 4, 3} ; ;
    vector<int> v(arr,arr+11) ;
    cout << solve(v) << endl;

}