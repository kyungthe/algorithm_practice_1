#include <iostream>

using namespace std;

char words[5][5], answers[10][10];
int testCase, N, y, x;
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

/*
	1. 첫번째 글자를 찾는다.( (0,0)부터 순서대로 검색 )
	2. 찾은 글자가 첫번째 글자와 다르면 1번으로(순서는 유지)
	3. 찾은 글자가 첫번째 글자와 같으면 다음 글자를 찾는다.(8방향 검색)
	4. 찾은 글자가 모두 다르면 실패.
	5. 찾은 글자가 같으면 다음 글자를 3번 방식으로 찾는다.
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

	y, x 위치까지는 단어 검색을 끝마친 상태
	y, x 위치를 중심으로 8방향 단어 검색
	단어가 있으면 (해당 위치, 다음단어)로 호출
	단어가 없으면 종료
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