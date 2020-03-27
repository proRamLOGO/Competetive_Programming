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
    
    for ( int T = 1 ; T <= t ; ++T ) {
        
        int n, k;
        cin >> n >> k ;
        
        vector<llui> v(n) ;
        vector< pair< llui, llui > > diff(n-1);
        llui dsum = 0 ;
        
        for ( int i = 0 ; i < v.size() ; ++i ) {
            cin >> v[i] ;
            if ( i > 0  ) {
                diff[i-1] = make_pair(v[i]-v[i-1],i-1) ;
                dsum += v[i]-v[i-1] ;
            }
        }
        
        sort(diff.begin(),diff.end()) ;

        llui kused = 0 ;
        for ( int i = n-2 ; i >= 0 ; --i ) {
            double f = ((double)diff[i].first/(double)dsum)*k ;
            diff[i].second = (llui)(f);
            kused += (llui)(f) ;
        }
        for ( int i = n-2 ; (i >= 0) && (kused < k) ; --i ) {
            ++(diff[i].second) ;
            kused++ ;
        }

        llui ans = 0 ;
        
        for ( int i = n-2 ; i >= 0 ; --i ) {

            llui da = (llui)(ceill((double)diff[i].first/(double)(diff[i].second+1))) ;
            ans = max( ans, da ) ;
        }
        
        cout << "Case #" << T << ": " << ans << endl ;
        
    }
    
}