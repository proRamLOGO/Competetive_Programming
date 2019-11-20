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

    int n ;
    cin >> n;

    //Prime Seive
    vector<bool> seive(10000000,1);
    
    seive[1] = 0 ;
    seive[0] = 0 ;
    seive[2] = 1 ;


    for ( llui i = 4 ; i < 10000000 ; i+=2 ) 
        seive[i] = 0 ;

    for ( llui i = 3 ; i < 10000000 ; i+=2 ) {

        if ( seive[i] ) {
            if ( i < n)
            for ( llui j = i*i ; j < 10000000 ; j+=i ) 
                seive[j] = 0 ;

        }

    }/* 
    @AlexadevsLPU
    @Alexastudentinfluencers
    #CodeLikeABoss
     */
    //Prime Seive ENDs

    llui arr[n] ;
    for ( auto i = 0 ; i < n ; ++i ) {
        cin >> arr[i] ;
        if ( arr[i]==1 ) {
            cout << "NO\n" ;
            continue ;
        }
        cout << arr[i] << "  " << sqrt(arr[i]) << (seive[(int)sqrt(arr[i])]) ;
        if( (sqrt(arr[i])==int(sqrt(arr[i]))) && seive[sqrt(arr[i])] )
            cout << " YES\n" ;
        else 
            cout << " NO\n" ;

    }

}