#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define left first
#define right second
#define MOD 1000000007
#define M 998244353
#define MI 748683265
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ulli;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<string> vs;

void pq( queue<int> q ) {
    while (!q.empty()) 
        cout << q.front() << ' ' , q.pop() ;
}

ulli power(ulli x,ulli y,ulli m) { 
    if (y == 0) 
        return 1; 
    ulli p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
} 

ulli gcd(ulli a, ulli b) { 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 

ulli modInverse(ulli a, ulli m) { 
    ulli g = gcd(a, m); 
    return power(a, m-2, m); 
} 
  

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t ;
    cin >> t ;
    
    while ( t-- ) {

        string s;
        cin >> s;
        int noofh = 0 ;
        vector < char > operators;
        vector < int > idx ;

        for ( int i = 0 ; i < s.size() ; ++i ) {
            if (s[i]==')') idx.pb(i) ;
            noofh += (s[i]=='#') ;
            if ( s[i]=='^' or s[i]=='&' or s[i]=='|' ) operators.push_back(s[i]);
        }

        vvll oprnds(noofh,vll(4,1)); // 0, 1, a, A

        // eval starts
        for ( int i : idx ) {

            ll x, y, z, t1, t2 ;
            
            vll op2 = oprnds[oprnds.size()-1] ,
                op1 = oprnds[oprnds.size()-2] , 
                res(4,1) ;
            
            char opr = operators[operators.size()-1] ;

            t2 = ( op2[0] + op2[1] + op2[2] + op2[3] ) % M ;
            t1 = ( op1[0] + op1[1] + op1[2] + op1[3] ) % M ;

            if ( opr == '^' ) {

                // Perform XOR

                res[1] = ( ( op1[0] * op2[1] ) + ( op1[1] * op2[0] ) + ( op1[2] * op2[3] ) + ( op1[3] * op2[2] ) ) % M ;
                res[0] = ( ( op1[0] * op2[0] ) + ( op1[1] * op2[1] ) + ( op1[2] * op2[2] ) + ( op1[3] * op2[3] ) ) % M ;
                res[2] = ( ( op1[0] * op2[2] ) + ( op1[1] * op2[3] ) + ( op1[3] * op2[1] ) + ( op1[3] * op2[1] ) ) % M ;
                res[3] = ( ( op1[3] * op2[0] ) + ( op1[0] * op2[3] ) + ( op1[1] * op2[2] ) + ( op1[2] * op2[1] ) ) % M ;

            } else if ( opr == '&' ) {

                // Perform AND

                res[0] = ( ( ( ( op2[0] * t1 )%M + op1[0] * t2 )%M - op1[0] * op2[0] + M )%M + ( op1[2] * op2[3] )%M + ( op1[3] * op2[2] )%M + M ) % M ;
                res[1] = ( op1[1] * op2[1] ) % M;
                res[2] = ( ( op1[2] * op2[2] ) + ( op1[1] * op2[2] ) + ( op1[2] * op2[1] ) ) % M;
                res[3] = ( ( op1[3] * op2[3] ) + ( op1[1] * op2[3] ) + ( op1[3] * op2[1] ) ) % M ;
            
            } else if ( opr == '|' ) {

                // Perform OR
                
                res[1] = ( ( ( ( op2[1] * t1 )%M + op1[1] * t2 )%M - op1[1] * op2[1] + M )%M + ( op1[2] * op2[3] )%M + ( op1[3] * op2[2] )%M + M ) % M ;
                res[0] = ( op1[0] * op2[0] ) % M ;
                res[2] = ( ( op1[2] * op2[2] ) + ( op1[0] * op2[2] ) + ( op1[2] * op2[0] ) ) % M ;
                res[3] = ( ( op1[3] * op2[3] ) + ( op1[0] * op2[3] ) + ( op1[3] * op2[0] ) ) % M ;
            }

            oprnds.pop_back();
            oprnds.pop_back();
            oprnds.push_back(res);

            operators.pop_back() ;

        }
        // eval done

        ulli sum = oprnds[oprnds.size()-1][0] + oprnds[oprnds.size()-1][1] + oprnds[oprnds.size()-1][2] + oprnds[oprnds.size()-1][3] ;
        ulli MI = modInverse(sum,M) ;

        // pro it up
        for ( int i = 0 ; i < noofh ; ++i ) { 
        
            oprnds[oprnds.size()-1][0] = ( oprnds[oprnds.size()-1][0] ) % M ;
            oprnds[oprnds.size()-1][1] = ( oprnds[oprnds.size()-1][1] ) % M ;
            oprnds[oprnds.size()-1][2] = ( oprnds[oprnds.size()-1][2] ) % M ;
            oprnds[oprnds.size()-1][3] = ( oprnds[oprnds.size()-1][3] ) % M ;
        }
        
        
        cout << oprnds[oprnds.size()-1][0] << ' ' << oprnds[oprnds.size()-1][1] << ' ' << oprnds[oprnds.size()-1][2] << ' ' << oprnds[oprnds.size()-1][3] << endl ;

    }

    return 0 ;
    
}