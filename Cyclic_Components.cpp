/*
E. Cyclic Components
Codeforces Round #479 (Div. 3)
https://codeforces.com/problemset/problem/977/E
*/

#include <bits/stdc++.h>

using namespace std ; 

template< typename T> 
class graph {

public:

    unordered_map< T, int > idx ; 
    unordered_map< T, vector<T> > adj_list ;  
    int no_of_nodes ;
    int no_of_edges ;


    graph() {
        no_of_edges = 0 ;
        no_of_nodes = 0 ;
    }

    bool addEdge( T u, T v ) {

        if ( idx.find(u) != idx.end() and idx.find(v) != idx.end() and find(adj_list[u].begin(),adj_list[u].end(),v)!=adj_list[u].end() )
            return false ;

        if ( idx.find(u) == idx.end() ) 
            idx[u] = no_of_nodes++ ;
            
        if ( idx.find(v) == idx.end() ) 
            idx[v] = no_of_nodes++ ;
            
        adj_list[u].push_back(v) ;
        adj_list[v].push_back(u) ;
        
        return true ;

    }

    void dfs( T* v, vector<bool>& visited ) {

        if ( v != NULL ) {
            visited[idx[*v]] = 1 ;
            for ( auto i : adj_list[*v] ) {
                if ( !visited[idx[i]] ) {
                    visited[idx[i]] = 1 ;
                    dfs(&i, visited) ;
                }
            }
        }
    }

    bool innerSolve( T src, vector<bool>& visited ) {

        T cr = src ;
        while (true) {
            if ( adj_list[cr].size() == 2 ) {
                T a = adj_list[cr][0] ;
                T b = adj_list[cr][1] ;
                T n ;
                if ( cr == src ) 
                    n = a ;
                if ( visited[idx[a]]==1 and visited[idx[b]]==1 and (src == a or src == b) )
                    return true ;
                if ( visited[idx[a]] )
                    n = b ;
                else if ( visited[idx[b]] )
                    n = a ;
                visited[idx[n]] = 1 ;
                cr = n ;
            }
            else 
                break ;
        }
        // dfs(&src, visited); 
        return false ;
    }

    int solve() {

        vector< bool > visited(no_of_nodes,0) ;
        int ans = 0 ;
        for ( auto i : adj_list ) {
            // cout << "Target Node is : " << i.first << endl ;
            if ( !visited[idx[i.first]] ) {
                visited[idx[i.first]] = 1 ;
                bool itz = innerSolve(i.first,visited) ;
                if (itz) {
                    // cout << "Including " << i.first << " wala group" << endl << endl ; ;
                    ++ans ;
                }
            }
            // cout << endl << endl ;
        }
        return ans ;

    }

};

int main() {

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin ) ;
    freopen( "output.txt", "w", stdout ) ;
    #endif

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n, m ;
    cin >> n >> m ; 

    if ( m < 3 ) {
        cout << 0 ;
        return 0 ;
    }

    graph<int> g ;

    for ( int i = 0 ; i < m ; ++i ) {
        int x, y ;
        cin >> x >> y ;
        if (x==y)
            continue ;
        g.addEdge(x,y) ;
    }

    cout << g.solve() ;
    

}

