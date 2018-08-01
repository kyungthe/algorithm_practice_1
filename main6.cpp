#include <iostream>

using namespace std;

char words[5][5], answers[10][10];
int testCase, N, y, x;
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

/*
	1. ù��° ���ڸ� ã�´�.( (0,0)���� ������� �˻� )
	2. ã�� ���ڰ� ù��° ���ڿ� �ٸ��� 1������(������ ����)
	3. ã�� ���ڰ� ù��° ���ڿ� ������ ���� ���ڸ� ã�´�.(8���� �˻�)
	4. ã�� ���ڰ� ��� �ٸ��� ����.
	5. ã�� ���ڰ� ������ ���� ���ڸ� 3�� ������� ã�´�.
*/

bool hasWord(int y, int x, char word)
{
	if ((0 > y || 5 >= y) || (0 > x || 5 >= x))
		return false;

	if (words[y][x] == word)
		return true;
	else
		return false;
}

/*
	searchWord

	y, x ��ġ������ �ܾ� �˻��� ����ģ ����
	y, x ��ġ�� �߽����� 8���� �ܾ� �˻�
	�ܾ ������ (�ش� ��ġ, �����ܾ�)�� ȣ��
	�ܾ ������ ����
*/

void searchWord(int y, int x, char* word, int order)
{
	if (!word[order])
	{
		cout << word << " YES" << endl;
	}

	for (size_t i = 0; i < 8; i++)
	{
		if (hasWord(y + dy[i], x + dx[i], word[order]))
			searchWord(y + dy[i], x + dx[i], word, order + 1);
	}

	cout << word << " NO" << endl;
}

void solve()
{
	bool find = false;
	for (size_t k = 0; k < testCase; k++)
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (words[i][j] == answers[k][0])
				{
					searchWord(i, j, answers[k], 0);
					find = true;
				}
			}
		}
		if (!find)
		{
			cout << answers[k] << " NO" << endl;
		}
		find = false;
	}
}

void input()
{
	cin >> N;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			cin >> words[i][j];
		}
	}
	
	cin >> testCase;
	for (size_t i = 0; i < testCase; i++)
	{
		cin >> answers[i];
	}
}

void output()
{

}

int main()
{
	input();
	solve();
	output();

	return 0;
}