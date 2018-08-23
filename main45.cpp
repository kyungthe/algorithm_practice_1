/* https://www.acmicpc.net/problem/1260 Quiz */

#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

int graph[MAX][MAX];
int visit[MAX];

void DFS(int v)
{
	visit[v] = 1;

	cout << v << " ";

	for (int i = 1; i < MAX; i++)
		if (!visit[i] && graph[v][i])
			DFS(i);
}

void BFS(int v)
{
	queue<int> q;
	q.push(v);
	visit[v] = 1;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		cout << v << " ";

		for (int i = 1; i < MAX; i++)
		{
			if (!visit[i] && graph[v][i])
			{
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

void Clear()
{
	for (int i = 0; i < MAX; i++)
		visit[i] = 0;
}

int main()
{
	int N, M, V;
	
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		graph[start][end] = graph[end][start] = 1;
	}

	DFS(V);
	Clear();
	cout << "\n";
	BFS(V);

	return 0;
}