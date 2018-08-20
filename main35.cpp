/* https://www.acmicpc.net/problem/1427 Quiz */

#include <iostream>
#include <array>

using namespace std;

int main()
{
	int N;
	array<int, 10> num = { 0, };

	cin >> N;

	int index = N % 10;
	num[index]++;
	N /= 10;
	while (N)
	{
		int index = N % 10;
		num[index]++;
		N /= 10;
	}

	for (int i = num.max_size() - 1; i >= 0; i--)
	{
		for (size_t j = 0; j < num[i]; j++)
		{
			cout << i;
		}
	}

	return 0;
}