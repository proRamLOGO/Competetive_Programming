// Author: proRam
// Name: Shubh Bansal
// Dated: May 17, 2020
// Question: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d

#include <bits/stdc++.h>

using namespace std;

int getMid(int s, int e) { return s + (e -s)/2; }  
  
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)  {
    
    if (qs <= ss && qe >= se)  
        return st[si];  
  
    if (se < qs || ss > qe)  
        return 0;  
  
    int mid = getMid(ss, se);  
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + getSumUtil(st, mid+1, se, qs, qe, 2*si+2);  
}  

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) {
    
    if (i < ss || i > se)  
        return;  
  
    st[si] = st[si] + diff;  
    if (se != ss) {  
        int mid = getMid(ss, se);  
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);  
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);  
    }  
}  
  
void updateValue(int arr[], int *st, int n, int i, int new_val) {  
    
    // if (i < 0 || i > n-1) {  
    //     cout<<"Invalid Input";  
    //     return;  
    // }  
    int diff = new_val - arr[i];  
  
    arr[i] = new_val;  
    
    updateValueUtil(st, 0, n-1, i, diff, 0);  
}  
  
int getSum(int *st, int n, int qs, int qe) {  
    
    // if (qs < 0 || qe > n-1 || qs > qe){  
    //     cout<<"Invalid Input";  
    //     return -1;  
    // }  
  
    return getSumUtil(st, 0, n-1, qs, qe, 0);  
}  
  
int constructSTUtil(int arr[], int ss, int se, int *st, int si) {  
  
    if (ss == se) {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
  
    int mid = getMid(ss, se);  
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +  
            constructSTUtil(arr, mid+1, se, st, si*2+2);  
    return st[si];  
}  
  
int *constructST(int arr[], int n) {  
    
    int x = (int)(ceil(log2(n)));  
    int max_size = 2*(int)pow(2, x) - 1;  
    int *st = new int[max_size];  
    
    constructSTUtil(arr, 0, n-1, st, 0);  
    return st;  
} 


int32_t main(int argc, char** argv) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    int t ;
    cin >> t ;
    for ( int _ = 0 ; _ < t ; ++_ ) {

        int ans = 0, n, q;
        cin >> n >> q ;
        int *v;
        v = new int[n] ;
        for ( int i = 0 ; i < n ; ++i ) {
            cin >> v[i] ;
            v[i] *= (i+1) ;
            if ( i&1 ) v[i]*=-1 ;
        }

        int *st = constructST(v, n);  

        while( q-- ) {

            char c ;
            cin >> c ;

            if ( c=='U' ) {
                int idx, nv ;
                cin >> idx >> nv ;
                nv *= idx ;
                --idx ;
                if ( idx&1 ) nv *= -1 ;
                updateValue(v, st, n, idx, nv); 
            } else {
                int l,r ;
                cin >> l >> r ;
                int query = getSum(st, n, l-1, r-1) ;
                cout << query << endl ;
                ans += query ;
            }

        }

        cout << "Case #" << _+1 << ":" << ans << endl << endl << endl ;
    }

    return 0 ;   

}
