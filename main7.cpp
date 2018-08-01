/*
	https://algospot.com/judge/problem/read/PICNIC ����
*/


#include <iostream>

using namespace std;

int isMatch[10], friends[10][10], c, n, m, friendCount;

/*
	1. ¦�� �ִ°�?
	2. ¦�� ������ pass(����� �ʿ� ����)
	3. ¦�� ������ ģ���ΰ�?
	4. ģ���̸� ¦�� ������
	5. ģ���� �ƴϸ� �ٸ� ģ�� Ž��
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