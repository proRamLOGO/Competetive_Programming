#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long ;

inline bool isvalid( vector<ll> v ) {
    
    ll asum = 0;
    asum = accumulate(v.begin(),v.end(),asum) ;
    int n = v.size() ;
    ll minsum = (n*(n-1))>>1 ;

    return (asum>=minsum) ;
}

inline bool isperfect( vector<ll> v ) {

    for ( int i = 0 ; i < v.size() ; ++i ) {
        if ( v[i]!=i )
            return false ;
    }
    return true ;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout);
    #endif

    int n ; cin >> n ;
    vector<ll> v(n) ; 
    for ( auto &i : v ) cin >> i ;
    
    if ( !isvalid(v) or isperfect(v) ) {
        cout << -1 << '\n' ;
        return 0;
    }

    // check if appearnece is double
    int sidx = -1 ;
    unordered_set<ll> s ;
    for ( int i = 0 ; i < n ; ++i ) {
        if ( s.find(v[i])!=s.end() ) {
            sidx = i ;
            break ;
        } else {
            s.insert(v[i]) ;
        }
    }

    if ( sidx == -1 ) {

        // find first (s[x]>[y]) pair 
        int x;
        x=-1 ;
        for ( int i = n-1 ; i>0 ; --i ) {
            if ( v[i]<v[i-1] ) {
                x = i ;
                break ;
            }
        }
        if ( x==-1 ) {
            // find index of first element >= n, till then store all used numbers.
            unordered_set<ll> used ;
            int mtnidx = -1 ;
            for ( int i = 0 ; i < n ; ++i ) {
                if ( v[i]>=n ) {
                    mtnidx = i ;
                    break ;
                }
                used.insert(v[i]) ;
            }
            for ( int i = n-1 ; i > 0 ; --i  ) {
                if ( used.find(i) == used.end() ) {
                    v[mtnidx++] = i ;
                }
            }
            if ( used.find(0) == used.end() ) {
                v[mtnidx++] = 0 ;
            }

        } else {

            // replace x-1 with n-1
            swap(v[x-1],v[n-1]) ;
            sort(v.begin()+x,v.end()) ;
            reverse(v.begin()+x,v.end()) ;
        
        }

        for ( const auto &i : v ) {
            cout << i << ' ' ;
        }
        cout << '\n' ;
        return 0 ;

    }

    else {

        // find smallest positive integer non existant till repetition
        ll m = v[0] ;
        unordered_set<ll> usin ;
        for ( int i = 0 ; i < sidx ; ++i ) {
            usin.insert(v[i]) ;
            m = min(m,v[i]) ;
        }
        --m ;
        usin.insert(m) ;
        v[sidx] = m ;
        
        vector<ll> lastelements ;
        for ( ll i = n-1 ; i > 0 ; --i ) {
            if ( usin.find(i) == usin.end() ) {
                lastelements.emplace_back( i ) ;
            }
        }
        if ( usin.find(0) == usin.end() ) {
            lastelements.emplace_back( 0 ) ;
        }

        for ( int i = sidx+1 ; i < n ; ++i ) 
            v[i] = lastelements[i-sidx-1] ;

    
        for ( const auto &i : v ) {
            cout << i << ' ' ;
        }
        cout << '\n' ;
        return 0 ;
    
    }
       
}
