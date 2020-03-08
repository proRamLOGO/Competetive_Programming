#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    string ones[20] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                        "Ten", "Eleven", "Twelve", "Thirhteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nignteen" } ;
    string tens[11] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty", "Hundered" } ;

    ull num ;
    cin >> num ;

    int digits = ceil(log10l(num)) ;
    
    //Billion
    string ans = "" ;
    if ( digits == 10 ) {
        ans += ones[num/1000000000] + " Billion";
    }

    //Million
    int mil = (num/1000000)%1000 ;
    string m = "" ;
    m += ones[mil/100] ;
    if ( m.size() > 0 ) m = " " + m + " Hundered" ;
    mil %= 100 ;
    if ( mil < 20 and mil > 0 ) {
        m += " " + ones[mil] ;
    } else if ( mil != 0 ){
        m += " " + tens[mil/10] + " " + ones[mil%10] ;
    }
    if ( m.size() != 0 )
        ans += m + " Million" ;

    //Thousands
    mil = (num/1000)%1000 ;
    m = "" ;
    m += ones[mil/100] ;
    if ( m.size() > 0 ) m = " " + m + " Hundered" ;
    mil %= 100 ;
    if ( mil < 20 and mil > 0) {
        m += " " + ones[mil] ;
    } else if ( mil != 0 ){
        m += " " + tens[mil/10] + " " + ones[mil%10] ;
    }
    if ( m.size() != 0 )
        ans += m + " Thousand" ;

    //Last
    mil = (num)%1000 ;
    m = "" ;
    m += ones[mil/100] ;
    if ( m.size() > 0 ) m = " " + m + " Hundered" ;
    mil %= 100 ;
    if ( mil < 20 and mil > 0 ) {
        m += " " + ones[mil] ;
    } else if ( mil != 0 ){
        m += " " + tens[mil/10] + " " + ones[mil%10] ;
    }
    if ( m.size() != 1 )
        ans += m ;

    cout << ans << endl ;

    return 0 ;

}