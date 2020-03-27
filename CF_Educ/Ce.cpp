#include <bits/stdc++.h>
#define llui long long unsigned int 
#define fr first
#define sc second
#define mp make_pair 
using namespace std ;
  
int main() { 

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    t=1 ;

    while ( t-- ) {

        int n,m,k ;
        cin >> n >> m >> k ;
        vector< pair< int , int > > s(k),f(k) ;
        bool ae = true ;
        for ( int i = 0 ; i < k ; ++i ) {
            int x,y ; 
            cin >> x >> y ;
            s[i] = mp(x,y) ;
            if ( x>n or y>m )
                ae = false ;
        }
        for ( int i = 0 ; i < k ; ++i ) {
            int x,y ; 
            cin >> x >> y ;
            f[i] = mp(x,y) ;
            if ( x>n or y>m )
                ae = false ;
        }

        if ( !ae ) {
            cout << -1 << endl ;
            break ;
        }

        vector<string> vs(k) ;

        for ( int i = 0 ; i < k ; ++i ) {
            int h = f[i].first - s[i].first ;
            int v = f[i].second - s[i].second ;
            // cout << h  << ' ' << v << endl ;
            string s = "" ;
            if ( h < 0 ) {
                for ( int j = 0 ; j < -h ; ++j )
                    s += "U" ;
            } else {
                for ( int j = 0 ; j < h ; ++j )
                    s += "D" ;
            }
            if ( v < 0 ) {
                for ( int j = 0 ; j < -v ; ++j )
                    s += "L" ;
            } else {
                for ( int j = 0 ; j < v ; ++j )
                    s += "R" ;;
            }
            // cout << s << endl ;
            vs[i] = s ;
        }

        // sort(vs.begin(),vs.end()) ;
        string ans = "" ;
        int idx = 0 ;
        string index[] = { "D", "DL", "DR", "L", "R", "U", "UL", "UR" } ;

        int l=0,r=0 ;
        while ( l < k ) {

            while ( index[idx][0] == vs[r][0] and index[idx][index[idx].size()-1] == vs[r][vs[r].size()-1] and r<k ) 
                ++r ;
            
            if ( (int)(index[idx].size())==2 ) {

                int maxv=0, maxh=0 ;
                for ( int j = l ; j < r ; ++j ) {
                    
                    int v=0, h=0 ;
                    for ( auto c : vs[j] ) {
                        if ( c=='U' or c=='D' ) {
                            ++v ;
                        } else 
                            break ;
                    }
                    h = (int)(vs[j].size())-v ;
                    maxv = max(maxv,v) ;
                    maxh = max(maxh,h) ;
                }

                string temp ="" ;
                if ( vs[l][0] =='D' )  {
                for ( int j = 0 ; j < maxv ; ++j )
                    temp += "D" ;
                } else {
                for ( int j = 0 ; j < maxv ; ++j )
                    temp += "U" ;
                }
                if ( vs[l][vs[l].size()-1] =='L' )  {
                for ( int j = 0 ; j < maxh ; ++j )
                    temp += "L" ;
                } else {
                for ( int j = 0 ; j < maxh ; ++j )
                    temp += "R" ;
                }
                //Undo
                if ( vs[l][0] =='D' )  {
                for ( int j = 0 ; j < maxv ; ++j )
                    temp += "U" ;
                } else {
                for ( int j = 0 ; j < maxv ; ++j )
                    temp += "D" ;
                }
                if ( vs[l][vs[l].size()-1] =='L' )  {
                for ( int j = 0 ; j < maxh ; ++j )
                    temp += "R" ;
                } else {
                for ( int j = 0 ; j < maxh ; ++j )
                    temp += "L" ;
                }

                ans += temp ;
            
            } else {

                int maxm = 0 ;
                for ( int j = l ; j < r ; ++j ) {
                    maxm = max(maxm,(int)(vs[j].size())) ;
                }

                string temp ="" ;
                if ( vs[l][0] =='D' )  {
                for ( int j = 0 ; j < maxm ; ++j )
                    temp += "D" ;
                } else if ( vs[l][0] =='L' ) {
                for ( int j = 0 ; j < maxm ; ++j )
                    temp += "L" ;
                } else if ( vs[l][0] =='U' ) {
                for ( int j = 0 ; j < maxm ; ++j )
                    temp += "U" ;
                } else if ( vs[l][0] =='R' ) {
                for ( int j = 0 ; j < maxm ; ++j )
                    temp += "R" ;
                }
                //Undo
                if ( vs[l][0] =='D' )  {
                for ( int j = 0 ; j < maxm ; ++j )
                    temp += "U" ;
                } else if ( vs[l][0] =='L' ) {
                for ( int j = 0 ; j < maxm ; ++j )
                    temp += "R" ;
                } else if ( vs[l][0] =='U' ) {
                for ( int j = 0 ; j < maxm ; ++j )
                    temp += "D" ;
                } else if ( vs[l][0] =='R' ) {
                for ( int j = 0 ; j < maxm ; ++j )
                    temp += "L" ;
                }

                ans += temp ;

            }

            ++idx ;
            l = r ;

        }

        cout << ans.size() << endl << ans << endl ;

    }

}
