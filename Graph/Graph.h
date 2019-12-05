#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
	int V;
	vector<vector<int>>graph;
	bool* visited;

public:
	Graph(int v)
	{
		this->V = v;
		visited = new bool[V];
		for (int i = 0; i < V; i++) { visited[i] = false; }
		graph.resize(V);
	}

	void addEdge(int u, int v);
	void BFS(int x);
	void DFS(int vertex);
	bool isBridge(int u, int v);
	void reset();
};