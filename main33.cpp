/* https://www.acmicpc.net/problem/10989 Quiz */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count[10001] = { 0, };
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		count[temp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < count[i]; j++)
			cout << i << "\n";
	}

	return 0;
}