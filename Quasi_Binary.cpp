#include <bits/stdc++.h>
using namespace std ;

int count_digits( int num ) {

    int cnt = 0 ;
    while( (num/=10)!=0 ) ++cnt ;
    return cnt+1 ;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num ;    
    cin >> num ;

    int digits ;
    digits = count_digits(num) ;
    // cout << digits << endl ;

    int num_digits[digits], max_digit = 0 ;

    for ( int i = digits-1 ; i>-1 ; --i ) {
        num_digits[i] = num%10 ;
        num/=10 ;
        max_digit = max( max_digit, num_digits[i] ) ;
    }

    int numbers[9][6] = {0} ;

    for ( int i = 0 ; i < max_digit ; ++i ) {
        for (  int j = 0 ; j < digits ; ++j ) {
            if ( i==0 )
                numbers[i][j] = 0 ;
            if ( num_digits[j] > 0 ) {
                --num_digits[j] ;
                ++numbers[i][j] ;
            }
        }
    }

    cout << max_digit << endl ;
    for ( int i = 0 ; i < max_digit ; ++i ) {
        int ans = 0 ;
        for (  int j = 0 ; j < digits ; ++j ) {
            ans *= 10 ;
            ans += numbers[i][j] ;
        }
        cout << ans << ' ' ;
    }
    cout << endl ;

    return 0 ;

}