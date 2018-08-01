/*
	https://algospot.com/judge/problem/read/PICNIC 문제
*/


#include <iostream>

using namespace std;

int isMatch[10], friends[10][10], c, n, m, friendCount;

/*
	1. 짝이 있는가?
	2. 짝이 있으면 pass(고려할 필요 없음)
	3. 짝이 없으면 친구인가?
	4. 친구이면 짝을 지어줌
	5. 친구가 아니면 다른 친구 탐색
*/

void picnic(int p)
{
	for (size_t j = 0; j < n; j++)
	{
		if (friends[p][j])
		{
			if (!isMatch[j])
			{
				isMatch[p] = isMatch[j] = 1;
				friendCount++;
				break;
			}
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		if (!isMatch[i])
			picnic(i);
	}
}

void input()
{
	int a, b;

	cin >> c;
	for (size_t i = 0; i < c; i++)
	{
		cin >> n >> m;
		for (size_t j = 0; j < m; j++)
		{
			cin >> a >> b;
			friends[a][b] = friends[b][a] = 1;
		}
	}
}

void output()
{
	cout << friendCount << endl;
}

int main()
{
	input();
	picnic(0);
	output();

	return 0;
}