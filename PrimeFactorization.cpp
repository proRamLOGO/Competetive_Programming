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
#define g(x) get<x>

using namespace std;
 
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

class seive {

public:

    vector<bool> isP ;
    vll primes, spf ;
    ll limit, maxPno, minPno=2ll ;

    seive( ll limit ) {
        isP.resize(limit) ;
        spf.resize(limit) ;
        this->limit = limit ;

        // this->__init_seive__() ;
        // Construction of Seove starts
        fill(all(isP),true) ;
        isP[0] = isP[1] = false ;

        for ( ll i = 2 ; i < limit ; ++i ) {
            if ( isP[i] ) {
                spf[i] = i ;
                primes.pb(i) ;
                for ( ll j = i*i ; j < limit ; j+=i ) {
                    isP[j] = false ;
                    spf[j] = i ;
                }
            }
        }
        maxPno = primes[len(primes)-1] ;
    }

    int noOfPrimes() {
        return this->primes.size() ;
    }

    int location( int pno ) {
        return binary_search(all(primes),pno) ;
    }

};

seive PS(1e5);
vector< int > highestPower( PS.noOfPrimes(), 0 ) ;

ll fpow( ll base, ll exp ) {

    while ( exp>0 ) {
        if ( exp&1 ) {
            base *= base ;
            exp >>= 1 ;
        }
    }
    return base ;

}

void primeFactorize( int n ) {
    unordered_map<int,int> pf ;
    while ( n!=1 ) {
        pf[PS.spf[n]]++ ;
        n /= PS.spf[n] ;
    }
    for ( auto i : pf ) {
        int loc = PS.location(i.first) ;
        if ( highestPower[loc] < i.second )
            highestPower[loc] = i.second ;
    }
}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n, m ;
    cin >> n >> m ;
    vector<int> v(n) ;
    for ( int i = 0 ; i < n ; ++i ) {
        cin >> v[i] ;
        primeFactorize(n) ;
    }

    ll lcm = 1 ;
    for ( int i = 0 ; i < highestPower.size() ; ++i ) {
        if ( highestPower[i] != 0 ) {
            lcm *= fpow(PS.primes[i],highestPower[i]) ;
        }
    }

    ll limit = ceil(m/lcm) ;

    for ( int i = 0 ; limit >= PS.primes[i] ; ++i ) {
        if ( highestPower[PS.primes[i]] != 0 ) {
            
        }
    }

    return 0 ;

}