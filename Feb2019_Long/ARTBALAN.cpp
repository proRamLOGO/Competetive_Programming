#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

bool cmp ( int x, int y ) {
    return x >= y ;
}

int binSearch1( vector<int> &v , int x ) {

    int hi, lo, mid, ans=-1 ;
    hi = v.size() - 1 ;
    lo = 0;

    while ( hi >= lo ) {

        mid = (hi+lo) / 2 ;

        if ( v[mid] == x ) {
            ans = mid ;
            hi = mid-1 ;
        }
        else if  ( v[mid] < x )
            hi = mid - 1 ;  
        else 
            lo = mid + 1 ;

    }

    return ans ;

}

int binSearch2( vector<int> &v , int x ) {

    int hi, lo, mid, ans=-1 ;
    hi = v.size() - 1 ;
    lo = 0;

    while ( hi >= lo ) {

        mid = (hi+lo) / 2 ;

        if ( v[mid] == x ) {
            ans = mid ;
            lo = mid+1 ;
        }
        else if  ( v[mid] < x )
            hi = mid - 1 ;  
        else 
            lo = mid + 1 ;

    }

    return ans ;

}

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        string s ;
        cin >> s ;

        vector< int > alpha(25) ;

        for ( auto c : s ) {

            int j = c - '0' ;
            j -= 17 ;
            ++alpha[j] ;

        }

        sort( alpha.begin(), alpha.end(), cmp ) ;

        alpha.resize( s.length() ) ;

        int alpha0 = binSearch1( alpha, 0 ) ;

        //cout << alpha0 << ' ' << alpha1 << endl ;

        int n = s.length(), ans = INT_MAX, res  ;

        vector< int > fact(n), reset(n) ;

        for ( auto i = 1 ; i <= n ; ++i ) {
            
            fact = reset ;
            res = 0;

            if ( n%i == 0 ) {

                for ( auto y = 0 ; y < n/i ; ++y ) 
                    fact[y] = i ;

            }
            
            int fact0 = binSearch1( fact, 0 ) ;

            if ( fact0 == alpha0 ) {
                
                int pos = binSearch2( alpha, i ) ;

                for ( auto y = i+1 ; y < n ; ++y ) 
                    res += i - alpha[y] ;

            }

            else {
                for ( auto y = 0 ; y < n ; ++y ) {

                    if ( fact[y] == 0 && alpha[y] != 0 )
                        res += alpha[y] ;
                    else if ( fact[y] != 0 && alpha[y] == 0 )
                        res += fact[y] ;

                }
            }

            if ( res <= ans )
                ans = res ; 

        }

        
        cout << ans << endl ;


        /*
        for ( auto c : alpha ) 
            cout << c << ' ' ;
        cout << endl ; 
        */
        

    }


}