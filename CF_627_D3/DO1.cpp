#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define llui long long unsigned int 
#define li long int 

using namespace std ;
using namespace __gnu_pbds;
 
int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    li n ;
    cin >> n ;

    llui arr[n];
    llui brr[n];
    
    for(li i=0;i<n;i++)
    cin>>arr[i];
    
    for(li i=0;i<n;i++)
    cin>>brr[i];
     
    ord_set< pair<llui ,llui> > suck;
    li ans=0;
    for ( li i = n-1 ; i >= 0 ; --i ) { 
        ans+=suck.order_of_key({arr[i]-brr[i],-1}) ;
        suck.insert({brr[i]-arr[i],i} ) ;           
    }
    
    cout<<ans<<endl;
    
    return 0;

}
