#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

class graph {
public:
    vector< list<int> > adjList ;
    graph( int n ) {
        this->adjList.resize(n+1) ;
    }
    void addEdge( int x, int y ) {
        this->adjList[x].push_back(y) ;
        this->adjList[y].push_back(x) ;
    }
    
    void dfs_helper( int node, vector<bool> &visited, vector<int> &ans ) {
        
        bool isavailable[4]  ;
        memset( isavailable, true, sizeof(isavailable) ) ;
        
        for ( auto itr : this->adjList[node] ) {
            if ( visited[itr] ) 
                isavailable[ans[itr]-1] = false ;
        }
        
        for ( int i = 0 ; i < 4 ; ++i ) {
            if ( isavailable[i] ) {
                ans[node] = i+1 ;
                break ;
            }
        }
        
    }
    
    vector< int > dfs(void) {
        int N = this->adjList.size()-1 ;
        vector<int> ans(N+1) ;
        vector<bool> visited(N+1,false) ;
        for ( int i = 1 ; i <= N ; ++i ) {
            if (!visited[i]) {
                visited[i] = true ;
                dfs_helper(i,visited,ans) ;
            }
        }
        return ans ;
    }
    
} ;

vector<int> solution(int N, vector< vector<int> >& paths) {
     
    graph g(N);
    for( auto i : paths ) {
        g.addEdge(i[0],i[1]) ;
    }
    
    vector< int > ans = g.dfs() ;
    ans.erase(ans.begin()) ;
    return ans ;
    
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n ;
    vector< vector< int > > paths ;
    int x,y ;
    cin >> x ;
    while ( x!=-1 ) {
        cin >> y ;
        vector<int> np(2) ;
        np[0] = x ;
        np[1] = y ;
        paths.push_back(np) ;
        cin >> x ;
    }

    vector< int > ans = solution(n,paths) ;
    for ( auto i : ans ) 
        cout << i << ' ' ;
    cout << endl ;

}