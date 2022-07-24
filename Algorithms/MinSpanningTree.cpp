#include<iostream>
#include<climits>
#include<stdio.h>

using namespace std;
#define V 9

int minKey(int key[], bool mst[]){
	int min = INT_MAX, minIndex;
	for (int v = 0; v < V; v++)
		if (mst[v] == false && key[v] < min)
			min = key[v], minIndex = v;
	return minIndex;
}

void Prim(int graph[V][V]){
	int visited[V];
	int key[V];
	bool mst[V];
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mst[i] = false;
	key[0] = 0;
	visited[0] = -1;
	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey(key, mst);
		mst[u] = true;
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mst[v] == false && graph[u][v] < key[v])
				visited[v] = u, key[v] = graph[u][v];
	}
	for (int i = 1; i < V; i++) {
		cout << visited[i] << endl;
	}
}

int main(){
	
	int graph[V][V] = { 0 };
	int vertices, edges, weight;
	int i, j;
	cin >> vertices;
	cin >> edges;
	for (int k = 1; k <= edges; k++){
		cin >> i >> j >> weight;
		graph[i][j] = weight;
		graph[j][i] = weight;
	}
	Prim(graph);
	return 0;
}