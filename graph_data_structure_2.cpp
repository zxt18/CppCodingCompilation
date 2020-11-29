#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; //number of vertices

    //Pointer to array cointaining adjacency lists

    list<int>*adj;

    void DFSUtil(int v, bool visited []);

public :
    Graph(int V); //Constructor

    void addEdge(int u, int v);

    void DFS(int v);  //vertices reachable from v

};

Graph::Graph(int V){
    this->V=V;
    adj= new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";

    for(auto i : adj[v]){  //goign through the adjacency list
        if(!visited[i])
            DFSUtil(i,visited);
    }
}

void Graph::DFS(int v)
{
    bool *visited= new bool [V];   //start with all vertices not visited
    for(int i=0; i<V; i++){
        visited[i]=false;
    }

    DFSUtil(v,visited);
}


long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
   Graph g(n);

   if(c_lib>=c_road){
       return n*c_lib;
    }


   for(int i=0; i<n; i++){
        g.addEdge(cities[i][0],cities[i][1]);
   }
   for(int i=1; i<n+1; i++){
        g.DFS(i);
   }
    return 0;

}









int main ()
{
    Graph g(4);
    g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
    cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";
	g.DFS(2);

	return 0;


}
