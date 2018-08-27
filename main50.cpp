/* https://www.acmicpc.net/problem/1021 Quiz */

#include <iostream>
#include <deque>
#include <array>

using namespace std;

void MoveLeft(deque<int>& deque, int n)
{
	for (int i = 0; i < n; i++)
	{
		int temp = deque[0];
		for (int j = 0; j < deque.size() - 1; j++)
			deque[j] = deque[j + 1];
		deque[deque.size() - 1] = temp;
	}
}

int SearchIndex(deque<int>& deque, int n)
{
	for (int j = 0; j < deque.size(); j++)
		if (deque[j] == n)
			return j;
}

int main()
{
	int N, M;
	deque<int> deque;
	array<int, 50> goal;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		deque.push_back(i);

	for (int i = 0; i < M; i++)
		cin >> goal[i];

	int operationCount = 0;
	for (int i = 0; i < M; i++)
	{
		int index = SearchIndex(deque, goal[i]);
		int halfSize = deque.size() / 2;
		MoveLeft(deque, index);
		if (index <= halfSize)
			operationCount += index;
		else
			operationCount += deque.size() - index;
		deque.pop_front();
	}

	cout << operationCount;

	return 0;
}