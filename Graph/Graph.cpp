#include "Graph.h";
#include <queue>;

void Graph::reset()
{
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
}

void Graph::addEdge(int u, int v)
{
	graph[u].push_back(v);
}

void Graph::DFS(int vertex)
{
	visited[vertex] = true;

	cout << vertex << " ";

	for (auto i = graph[vertex].begin(); i != graph[vertex].end(); i++)
	{
		if (!visited[*i])
		{
			DFS(*i);
		}
	}
}

bool Graph::isBridge(int u, int v)
{
	int i = 0;

	for (auto itr : graph[u])
	{
		if (itr == v) { graph[u].erase(graph[u].begin() + i); }
		i++;
	}
	i = 0;
	for (auto itr : graph[v])
	{
		if (itr == u) { graph[v].erase(graph[u].begin() + i); }
		i++;
	}

	DFS(0);

	addEdge(u, v);

	for (int i = 0; i < V; i++)
	{
		if (!visited[i]) { return true; }
	}

	return false;
}

void Graph::BFS(int vertex)
{
	queue<int>q;
	visited[vertex] = true;

	q.push(vertex);

	while (!q.empty())
	{
		vertex = q.front();

		cout << vertex << " ";
		q.pop();

		for (auto itr = graph[vertex].begin(); itr != graph[vertex].end(); itr++)
		{
			if (!visited[*itr])
			{
				visited[*itr] = true;
				q.push(*itr);
			}
		}
	}
}