#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

struct Edge{

	int src, dest, weight;
};


struct Graph{

	int V, E;
	struct Edge* edge;
};

struct Graph* createGraph(int vertices, int edges){

	struct Graph* graph = new Graph;
	graph->V = vertices;
	graph->E = edges;
	graph->edge = new Edge[edges];
	return graph;
}

void output(int dist[], int n){

	for (int i = 0; i < n; ++i) {
		if (dist[i] == INT_MAX)
			cout << "INFINITY" << endl;
		else
			cout << dist[i] << endl;
	}
}

void BellmanFord(struct Graph* graph, int src){

	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= V - 1; i++){
		for (int j = 0; j < E; j++){
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	for (int i = 0; i < E; i++){
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			cout << "FALSE" << endl;
			return;
		}

	}
	cout << "TRUE" << endl;
	output(dist, V);
}

int main(){

	int V, E;
	cin >> V >> E;

	int u, v, c;
	struct Graph* graph = createGraph(V, E);

	for (int i = 0; i<E; i++) {
		cin >> u >> v >> c;
		graph->edge[i].src = u;
		graph->edge[i].dest = v;
		graph->edge[i].weight = c;
	}

	BellmanFord(graph, 0);
	return 0;
}
