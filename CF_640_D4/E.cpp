// Author: proRam
// Name: Shubh Bansal
// Dated: 9/5/2020
// Question: https://codeforces.com/contest/1352/problem/C

#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

const int N = 8000;  // limit for array size
int n;  // array size
vector<int> t(2 * N);

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int32_t main(int argc, char** argv) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    int T ;
    cin >> T ;
    while(T--) {
        // int n ;
        cin >> n ;
        vector<int> v(n) ;
        for(int i = 0 ; i < n ; ++i) cin >> v[i] ;
        t.clear() ;
        for(int i = 0 ; i < n ; ++i) t[n+i] = v[i] ;
        build();
        // modify(0, 1);
        unordered_set<int> vals ;
        for(int i = 0 ; i < n ; ++i) {
            for(int j = i+1 ; j < n ; ++j) {
                vals.insert(query(i,j+1)) ;
                // cout << query(i,j+1) << ' ' ;
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; ++i) {
            if ( vals.find(v[i])!=vals.end() ) ++cnt ;
        }
        cout << cnt << endl ;

    }


    return 0 ;   

}
