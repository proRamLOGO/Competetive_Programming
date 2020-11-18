
  // Graph - Dijkstra's Algorithm
  
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f  

class Graph
{
    int V; 
    list<pair<int,int>>*adj; 
public :
    Graph(int V); //constructor
    void addEdge(int u,int v,int wt);
    void ShortestPath(int source);
};
Graph::Graph(int V)
{
    this->V=V;
    adj=new list< pair<int,int> >[V];
}
void Graph::addEdge(int u,int v,int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
void Graph::ShortestPath(int source)
{
  vector<int> dist(V,INF); 

  set<pair<int,int>> setds;  

  setds.insert(make_pair(0,source)); 
  dist[source]=0; 

  while(!setds.empty())
  {
     pair<int,int> temp=*(setds.begin()); 
     setds.erase(setds.begin());   

     int u=temp.second; 
     list<pair<int,int>>::iterator i;
     for(i=adj[u].begin();i!=adj[u].end();i++)
     {
         int v=(*i).first; 
         int weight=(*i).second; 

         if(dist[v]>dist[u]+weight) 
         {
             if(dist[v]!=INF)
                setds.erase(setds.find(make_pair(dist[v],v))); 
            dist[v]=dist[u]+weight;
            setds.insert(make_pair(dist[v],v)); 
         }
     }
  }
  cout<<"Vertex   distance from Source :\n";
  for(int i=0;i<V;i++)
   // cout<<"   "<<i<<"           "<<dist[i]<<"\n";
   printf(" %d \t\t %d\n",i,dist[i]);
}
int main()
{
    int V=9;
    Graph g(V);

    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,2,8);
    g.addEdge(7,6,1);
    g.addEdge(7,8,7);
    g.addEdge(2,8,2);
    g.addEdge(8,6,6);
    g.addEdge(2,3,7);
    g.addEdge(2,5,4);
    g.addEdge(6,5,2);
    g.addEdge(3,5,14);
    g.addEdge(3,4,9);
    g.addEdge(5,4,10);

    g.ShortestPath(0);

    return 0;
}
