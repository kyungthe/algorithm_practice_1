/* https://www.acmicpc.net/problem/10039 Quiz */

#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 5> arr;
	int result = 0;

	for (size_t i = 0; i < arr.max_size(); i++)
	{
		cin >> arr[i];
		if (arr[i] < 40)
			result += 40;
		else
			result += arr[i];
	}

	cout << result / 5 << endl;

	return 0;
}