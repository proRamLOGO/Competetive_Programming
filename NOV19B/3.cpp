#include <bits/stdc++.h>
#define llui long long unsigned int

using namespace std;

llui distance( vector < llui > p1, vector < llui > p2 ) {
	return (p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1])  ;
}

int main() {
	
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt","w",stdout) ;    
    #endif

	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;	

    int t ;
    cin >> t ;
	
    while ( t-- ) {
        
        llui X, Y ;
        int n,m,k ;
        cin >> X >> Y >> n >> m >> k ;
        vector< llui > vec(2), xy(2) ;
        vector< vector < llui > > N(n,vec), M(m,vec), K(k,vec) ; 
		vector< int > NM(n), MN(m), NK(n), MK(m) ;

		xy[0] = X, xy[1] = Y ;

	    for ( auto i = 0 ; i < n ; ++i )
			cin >> N[i][0] >> N[i][1] ;	    
	    for ( auto i = 0 ; i < m ; ++i )
			cin >> M[i][0] >> M[i][1] ;	    
	    for ( auto i = 0 ; i < k ; ++i )
			cin >> K[i][0] >> K[i][1] ;
	    
		// MK
	    for ( auto i = 0 ; i < m ; ++i ) {
			llui mindis = distance(M[i], K[0]) ;
			int idx = 0 ;
			for ( int j = 1 ; j < k ; ++j ) {
				llui newdis = distance(M[i], K[j]) ;
				if ( newdis < mindis ) {
					mindis = newdis ;
					idx = j ;
				}
			}
			MK[i] = idx ;
		}
	    
		// NK
	    for ( auto i = 0 ; i < n ; ++i ) {
			llui mindis = distance(N[i], K[0]) ;
			int idx = 0 ;
			for ( int j = 1 ; j < k ; ++j ) {
				llui newdis = distance(N[i], K[j]) ;
				if ( newdis < mindis ) {
					mindis = newdis ;
					idx = j ;
				}
			}
			NK[i] = idx ;
		}
	    
		// NM
	    for ( auto i = 0 ; i < n ; ++i ) {
			llui mindis = distance(N[i], M[0]) ;
			int idx = 0 ;
			for ( int j = 1 ; j < m ; ++j ) {
				llui newdis = distance(N[i], M[j]) ;
				if ( newdis < mindis ) {
					mindis = newdis ;
					idx = j ;
				}
			}
			NM[i] = idx ;
		}
		// MN
	    for ( auto i = 0 ; i < m ; ++i ) {
			llui mindis = distance(M[i], N[0]) ;
			int idx = 0 ;
			for ( int j = 1 ; j < n ; ++j ) {
				llui newdis = distance(M[i], N[j]) ;
				if ( newdis < mindis ) {
					mindis = newdis ;
					idx = j ;
				}
			}
			MN[i] = idx ;
		}

		//Proceeding to answer

		// xy->N->M->K 

		llui mindis = distance(N[0], xy) ;
		int idx = 0 ;
	    for ( auto i = 1 ; i < n ; ++i ) {
			llui newdis = distance(N[i],xy) ;
			if ( newdis < mindis ) {
				mindis = newdis ;
				idx = i ;
			}
		}

		long double ans1 = sqrt(mindis) + sqrt(distance(N[idx], M[NM[idx]] )) + sqrt(distance( M[NM[idx]], K[MK[NM[idx]]] )) ;
		
		// xy->M->N->K 

		mindis = distance(M[0], xy) ;
		idx = 0 ;
	    for ( auto i = 1 ; i < m ; ++i ) {
			long double newdis = distance(M[i],xy) ;
			if ( newdis < mindis ) {
				mindis = newdis ;
				idx = i ;
			}
		}

		long double ans2 = sqrt(mindis) + sqrt(distance(M[idx], N[MN[idx]] )) + sqrt(distance( N[MN[idx]], K[NK[MN[idx]]] )) ;

		if ( ans1 < ans2 ) 
			cout << setprecision(11) << ans1 << endl ;
		else
			cout << setprecision(11) << ans2 << endl ;

	}
	
	return 0;
}
