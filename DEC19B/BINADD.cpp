#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

llui add( string a, string b ) {
    
    bool flag = false;
    int n1 = a.size();
    int n2 = b.size();
    for ( int i = 0 ; i < n1 ; ++i )
        if (b[i] == '1')
            flag = true;
    if (!flag) 
        return 0;

    if (n1 < n2) {
        int l = n2 - n1;
        while (l--)
            a = '0' + a;
    }
    else if (n2 > n1 ) {
        int l = n2 - n1;
        while (l--)
            b = '0' + b;
    }

    int ans = 1;
    int idx = -1;
    for ( int i = a.size() - 1 ; i > -1 ; --i ){
        if (a[i] == b[i]){
            if (idx != -1)
                ans = max(ans, idx - i + 1);
            idx = -1;
        }
        if (a[i] == '1' && b[i] == '1')
            idx = i;
    }
    if (idx != -1)
        ans = max(ans, idx + 2);
    
    return ans;
}
int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while( t-- ) {
        string a, b ;
        cin >> a >> b ;
        cout << add(a, b) << endl ;
    }

    return 0;
}