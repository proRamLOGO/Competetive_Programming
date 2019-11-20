#include <bits/stdc++.h>
#define llui long long unsigned int 

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

};

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x ;
    cin >> x ;
    cout << x*x ;



}
