#include <iostream>
#include <list>

using namespace std;

class Graph {

	int V; //number of vertices

	list<int> *adj; //pointer to an array of adjacency lists of type int ;

public:

	Graph(int V);

	void add_edge(int v, int u);

	void BFS(int s); //source of the graph

};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::add_edge(int v, int u) {
	adj[v].push_back(u); // Add u to the list in v
}

void Graph::BFS(int s) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	list<int>queue;

	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;


	while (!queue.empty()) {

		s = queue.front();  //s is whatever in front of the queue
		cout << queue.front();
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}

		}

	}

}


int main() {
	Graph g(7);
	g.add_edge(0, 3);
	g.add_edge(0, 1);
	g.add_edge(1, 2);
	g.add_edge(2, 6);
	g.add_edge(6, 5);
	g.add_edge(5, 8);
	g.add_edge(2, 0);
	g.BFS(2);
	return 0;
}

