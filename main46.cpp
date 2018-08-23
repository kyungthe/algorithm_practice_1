/* https://www.acmicpc.net/problem/1966 Quiz */

#include <iostream>
#include <vector>

using namespace std;

void Shift(vector<int>& v, int start)
{
	int temp = v[start];
	int size = v.size() - 1;
	for (int i = start; i < size; i++)
		v[i] = v[i + 1];
	v[size] = temp;
}

int main()
{
	int T, N, M;
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		vector<int> v(N, 0);
		for (int j = 0; j < N; j++)
		{
			cin >> v[j];
		}
		int start = 0;
		for (size_t j = start; j < N; j++)
		{
			if (v[j] > v[start])
			{
				Shift(v, start);
				if (start == M)
					M = v.size();
				M--;
				j = start - 1;
			}
			if (j == N - 1)
			{
				if (start == M)
					break;
				start++;
				j = start;
			}
		}
		cout << start + 1 << "\n";
	}

	return 0;
}