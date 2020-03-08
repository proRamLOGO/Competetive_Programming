#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
 
using namespace std;
 
typedef long int ll;
typedef long int l;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<l> vl;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

vl spf(100001,1); 

void __init__seive() { 
    spf[1] = 1; 
    for ( l i = 2 ; i <= 100000 ; ++i ) {
        spf[i] = i ; 
    }
    for ( l i = 4 ; i <= 100000 ; i+=2 ) {
        spf[i] = 2 ; 
    }
  
    for ( l i = 3 ; i*i <= 100000 ; ++i ) { 
        if (spf[i] == i) { 
            for (long long j=i*i ; j <= 100000 ; j+=i ) {
                if (spf[j]==j) 
                    spf[j] = i; 
            }
        } 
    } 
} 
  
l pfactorise(l num) { 
    
    // vl pfactors(1,1); 
    unordered_map<l,l> cnt ;
    while (num != 1) { 
        // pfactors.pb(spf[num]); 
        ++cnt[spf[num]] ;
        num = (num/spf[num]) ; 
    } 

    l pwopopf = 1 ;
    for ( auto i : cnt) {
        if(((i.second)&1)) {
            pwopopf = pwopopf * i.first;
        }
    }
    
    return pwopopf ; 

} 

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    __init__seive() ;

    int t ;
    cin >> t ;
    
    while ( t--!=0 ) {

        // Inputs and prep
        l n, m ;
        cin >> n >> m ;
        bool x0=false, y0=false ;
        vector<l> xpv, ypv, xnv, ynv ;
        unordered_set<l> xps, yps, xns, yns ;
        for ( auto i = 0 ; i < n ; ++i ) {
            l x ;
            cin >> x ; 
            if ( x < 0 ) {
                xnv.pb(-x) ;
                xns.insert(-x) ;
            }
            else if ( x > 0 ) {
                xpv.pb(x) ;
                xps.insert((l)x) ;
            } else 
                x0 = true ;
        }
        for ( auto i = 0 ; i < m ; ++i ) {
            l y ;
            cin >> y ; 
            if ( y < 0 ) {
                ynv.pb(-y) ;
                yns.insert(-y) ;
            }
            else if ( y > 0 ) {
                ypv.pb(y) ;
                yps.insert((l)y) ;
            } else 
                y0 = true ;
        }

        l ans = 0 ;
        
        for ( int i = 0 ; i < xnv.size() ; ++i ) {

            // pair<vl,l> pff = pfactorise( xnv[i] ) ;
            // vl pf = pff.first ;
            l pwopopf = pfactorise( xnv[i] ) ; 
            // cout << MESS << endl ;
            for ( int j = 1 ; j < 318 ; ++j ) {
                
                ll pro = pwopopf*j*j ;
                if ( pro > 100000 ) 
                    break ;
                if ( xps.find(pro)!=xps.end() ) {
            
                    ll sr = (ll)sqrtl(xnv[i]*pro) ;
                    if ( yps.find(sr)!=yps.end() )
                        ++ans ;
                    if ( yns.find(sr)!=yns.end() )
                        ++ans ;
            
                }
            
            }

        }

        /* for ( auto i = 0 ; i < len(xpv) ; ++i ) {

            vl pf = pfactorise( xpv[i] ) ;
            ll MESS = 1 ;
            
            for ( int j = 0 ; j < 318 ; ++j ) {
                
                ll temp = MESS*i*i ;

                if ( xns.find(temp)!=xns.end() ) {
            
                    ll sr = sqrt(xpv[i]*temp) ;
                    if ( yps.find(sr)!=yps.end() )
                        ++ans ;
                    if ( yns.find(sr)!=yns.end() )
                        ++ans ;
            
                }
            
            }

        } */

        for ( int i = 0 ; i < len(ynv) ; ++i ) {

            // pair<vl,ll> pff = pfactorise( ynv[i] ) ;
            // vl pf = pff.first ;
            l pwopopf = pfactorise( ynv[i] ) ; 
            // cout << MESS << endl ;
             for ( int j = 1 ; j < 318 ; ++j ) {
                
                ll pro = pwopopf*j*j ;
                if ( pro > 100000 ) 
                    break ;

                if ( yps.find(pro)!=yps.end() ) {
            
                    ll sr = (ll)sqrtl(ynv[i]*pro) ;
                    if ( xps.find(sr)!=xps.end() )
                        ++ans ;
                    if ( xns.find(sr)!=xns.end() )
                        ++ans ;
            
                }
            
            } 

        }

        // Including Right Traingles ANGLED AT ORIGIN
        if ( x0 and y0 )
            ans += (n-1)*(m-1) ;
        else if ( x0 ) 
            ans += (n-1)*(m) ;
        else if ( y0 ) 
            ans += (n)*(m-1) ;

        /* for ( auto i = 0 ; i < len(ypv) ; ++i ) {

            vl pf = pfactorise( ypv[i] ) ;
            ll MESS = 1 ;
            
            for ( int j = 0 ; j < 318 ; ++j ) {
                
                ll temp = MESS*i*i ;

                if ( yns.find(temp)!=yns.end() ) {
            
                    ll sr = sqrt(ypv[i]*temp) ;
                    if ( xps.find(sr)!=xps.end() )
                        ++ans ;
                    if ( xns.find(sr)!=xns.end() )
                        ++ans ;
            
                }
            
            }

        } */

        cout << ans << endl ;

    }
    
    return 0 ;

}