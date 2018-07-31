#include <iostream>
#include <vector>

using namespace std;

int totalNode, totalEdge, sum, min = 0x7FFFFFFF;

struct NODE
{
	int vertex;
	int edge;
};

vector<NODE> nodes[11];

void dfs(int v, int e)
{
	sum += e;
	cout << "방문한 정점 : " << v << "\t비용 : " << e << "\t현재 비용 : " << sum << endl;
	for (size_t i = 0; i < nodes[v].size(); i++)
	{
		dfs(nodes[v][i].vertex, nodes[v][i].edge);
	}
	if (v == totalNode && min > sum)
		min = sum;
	sum -= e;
}

void solve()
{
	dfs(1, 0);
}

void input()
{
	int n;
	NODE node;

	cin >> totalNode >> totalEdge;

	for (size_t i = 0; i < totalEdge; i++)
	{
		cin >> n >> node.vertex >> node.edge;

		nodes[n].push_back(node);
	}
}

void output()
{
	cout << min << endl;
}

int main()
{
	input();
	solve();
	output();

	return 0;
}